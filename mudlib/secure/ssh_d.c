#include "/include/config.h"
#include "/include/ansi.h"

// /secure/ssh_d.c
// SSH Daemon — 完全無狀態設計
// session 狀態存在 player/guest 物件的 temp 裡，ssh_d 本身不持有任何 mapping。
// 這樣 ssh_d 被 GC 後重新載入也不會遺失任何連線。

inherit "/std/object";

string generate_uuid() {
    return sprintf("%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
        random(65536), random(65536),
        random(65536), random(65536),
        random(65536),
        random(65536), random(65536), random(65536));
}

void send_msg(string target_mudlib, string msg) {
    p2p_broadcast(msg, target_mudlib);
}

// ──────────────────────────────────────────────────────────
// CLIENT ROLE
// ──────────────────────────────────────────────────────────
void start_session(object player, string target_mudlib) {
    if (!player || !userp(player)) return;

    string session_id = generate_uuid();

    player->set_temp("ssh_pending",   session_id);
    player->set_temp("ssh_target",    target_mudlib);
    player->set_temp("ssh_player_id", object_name(player)); // 備援索引

    tell_object(player, HIM("[Fantasy Space] ") + "正在請求連線至 " + target_mudlib + "...\n");

    string msg = "fs_session|" + FS_MUDLIB_ID + "|" + target_mudlib +
                 "|connect|" + session_id + "|" + player->get_id() + "|" + player->query_name();
    send_msg(target_mudlib, msg);
}

void client_send_input(object player, string cmd) {
    string session_id = player->query_temp("ssh_session_id");
    string target     = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    string msg = "fs_session|" + FS_MUDLIB_ID + "|" + target +
                 "|input|" + session_id + "|" + cmd;
    send_msg(target, msg);
}

void client_send_disconnect(object player) {
    string session_id = player->query_temp("ssh_session_id");
    if (!session_id) session_id = player->query_temp("ssh_pending");
    string target = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    string msg = "fs_session|" + FS_MUDLIB_ID + "|" + target +
                 "|disconnect|" + session_id + "|Client closed";
    send_msg(target, msg);

    player->delete_temp("ssh_session_id");
    player->delete_temp("ssh_pending");
    player->delete_temp("ssh_target");
    tell_object(player, HIM("[Fantasy Space] ") + "連線已關閉，你回到了現實。\n");
}

// ──────────────────────────────────────────────────────────
// SERVER ROLE
// ──────────────────────────────────────────────────────────
void server_send_output(string target_mudlib, string session_id, string text) {
    string msg = "fs_session|" + FS_MUDLIB_ID + "|" + target_mudlib +
                 "|output|" + session_id + "|" + text;
    send_msg(target_mudlib, msg);
}

void server_send_disconnect(string target_mudlib, string session_id, string reason) {
    string msg = "fs_session|" + FS_MUDLIB_ID + "|" + target_mudlib +
                 "|disconnect|" + session_id + "|" + reason;
    send_msg(target_mudlib, msg);
}

// ──────────────────────────────────────────────────────────
// 封包接收解析 (由 interstellar_d 呼叫)
// ──────────────────────────────────────────────────────────
void receive_fs_session(string content) {
    string *parts = explode(content, "|");
    if (sizeof(parts) < 5) return;

    string from_mudlib = parts[1];
    string to_mudlib   = parts[2];
    string msg_type    = parts[3];
    string session_id  = parts[4];

    if (to_mudlib != FS_MUDLIB_ID && to_mudlib != "*") return;
    if (from_mudlib == FS_MUDLIB_ID) return;

    string payload = "";
    for (int i = 5; i < sizeof(parts); i++) {
        payload += parts[i];
        if (i < sizeof(parts) - 1) payload += "|";
    }

    // ── Client role ─────────────────────────────────────
    if (msg_type == "ack") {
        // 從所有在線玩家裡找有 ssh_pending == session_id 的那個
        object player = _find_player_by_temp("ssh_pending", session_id);
        if (player) {
            player->delete_temp("ssh_pending");
            player->set_temp("ssh_session_id", session_id);
            tell_object(player, HIM("[Fantasy Space] ") + "連線成功！你已登臨異界！\n\n");
            if (payload != "") tell_object(player, payload + "\n");
        }
        return;
    }

    if (msg_type == "deny") {
        object player = _find_player_by_temp("ssh_pending", session_id);
        if (player) {
            player->delete_temp("ssh_pending");
            player->delete_temp("ssh_target");
            tell_object(player, RED("連線被拒絕：" + payload + "\n"));
        }
        return;
    }

    if (msg_type == "output") {
        // 從 session_id 找玩家（用 ssh_session_id temp）
        object player = _find_player_by_temp("ssh_session_id", session_id);
        if (player) {
            tell_object(player, payload);
        }
        return;
    }

    if (msg_type == "disconnect") {
        // 作為 Client 收到
        object player = _find_player_by_temp("ssh_session_id", session_id);
        if (!player) player = _find_player_by_temp("ssh_pending", session_id);
        if (player) {
            tell_object(player, RED("\n【遠端伺服器中斷連線】" + payload + "\n"));
            player->delete_temp("ssh_session_id");
            player->delete_temp("ssh_pending");
            player->delete_temp("ssh_target");
            return;
        }
        // 作為 Server 收到：銷毀 guest
        object guest = _find_guest_by_session(session_id);
        if (guest) {
            tell_room(environment(guest), guest->query_name() + "化作一道光芒消失了。\n", ({ guest }));
            destruct(guest);
        }
        return;
    }

    // ── Server role ─────────────────────────────────────
    if (msg_type == "connect") {
        string *user_info = explode(payload, "|");
        string p_id   = (sizeof(user_info) > 0) ? user_info[0] : "guest";
        string p_name = (sizeof(user_info) > 1) ? user_info[1] : "Guest";

        object guest = clone_object("/std/guest.c");
        if (!guest) {
            send_msg(from_mudlib, "fs_session|" + FS_MUDLIB_ID + "|" + from_mudlib +
                     "|deny|" + session_id + "|無法建立訪客實體");
            return;
        }

        guest->set_id(p_id);
        guest->set_name(p_name + "@" + from_mudlib);
        guest->set_temp("ssh_session_id",  session_id);
        guest->set_temp("ssh_remote_mud",  from_mudlib);

        string welcome = HIG("歡迎來到 " + FS_MUDLIB_ID + "！這是一個全新的世界。\n");
        send_msg(from_mudlib, "fs_session|" + FS_MUDLIB_ID + "|" + from_mudlib +
                 "|ack|" + session_id + "|" + welcome);

        guest->move_to_start();
        tell_room(environment(guest), guest->query_name() + "化作一道光芒降臨此地。\n", ({ guest }));
        call_out("do_guest_look", 1, guest);
        return;
    }

    if (msg_type == "input") {
        object guest = _find_guest_by_session(session_id);
        if (guest) {
            guest->do_remote_cmd(payload);
        }
        return;
    }
}

void do_guest_look(object guest) {
    if (guest) guest->do_remote_cmd("look");
}

// ──────────────────────────────────────────────────────────
// 輔助：掃描在線物件找到有特定 temp 值的玩家
// ──────────────────────────────────────────────────────────
private object _find_player_by_temp(string key, string val) {
    object *all = users();
    foreach (object u in all) {
        if (u && userp(u) && u->query_temp(key) == val) return u;
    }
    return 0;
}

// 掃描所有物件找 guest（guest 繼承 user，但不在 users() 裡）
private object _find_guest_by_session(string session_id) {
    // guest 物件的 filename 是 /std/guest.c#N
    foreach (object ob in objects()) {
        if (!ob || ob->is_destructed()) continue;
        string fn = object_name(ob);
        if (strsrch(fn, "/std/guest.c#") == 0) {
            if (ob->query_temp("ssh_session_id") == session_id) return ob;
        }
    }
    return 0;
}
