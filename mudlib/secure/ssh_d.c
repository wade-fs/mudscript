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

void send_msg(string target_mudlib, mapping data) {
    data["from"] = FS_MUDLIB_ID;
    // 不加 p2p_ignore，讓接收方正常處理
    // 重複處理由 receive_fs_session 內的 from == FS_MUDLIB_ID 過濾
    p2p_broadcast(json_encode(data), FS_MUDLIB_ID);
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

    send_msg(target_mudlib, ([
        "tag": "fs_session",
        "to": target_mudlib,
        "type": "connect",
        "sid": session_id,
        "p_id": player->get_id(),
        "p_name": player->query_name()
    ]));
}

void client_send_input(object player, string cmd) {
    string session_id = player->query_temp("ssh_session_id");
    string target     = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    send_msg(target, ([
        "tag": "fs_session",
        "to": target,
        "type": "input",
        "sid": session_id,
        "payload": cmd
    ]));
}

void client_send_disconnect(object player) {
    string session_id = player->query_temp("ssh_session_id");
    if (!session_id) session_id = player->query_temp("ssh_pending");
    string target = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    send_msg(target, ([
        "tag": "fs_session",
        "to": target,
        "type": "disconnect",
        "sid": session_id,
        "payload": "Client closed"
    ]));

    player->delete_temp("ssh_session_id");
    player->delete_temp("ssh_pending");
    player->delete_temp("ssh_target");
    tell_object(player, HIM("[Fantasy Space] ") + "連線已關閉，你回到了現實。\n");
    player->sync_remote_ui();
}

// ──────────────────────────────────────────────────────────
// SERVER ROLE
// ──────────────────────────────────────────────────────────
void server_send_output(string target_mudlib, string session_id, string text) {
    send_msg(target_mudlib, ([
        "tag": "fs_session",
        "to": target_mudlib,
        "type": "output",
        "sid": session_id,
        "payload": text
    ]));
}

void server_send_disconnect(string target_mudlib, string session_id, string reason) {
    send_msg(target_mudlib, ([
        "tag": "fs_session",
        "to": target_mudlib,
        "type": "disconnect",
        "sid": session_id,
        "payload": reason
    ]));
}

// ──────────────────────────────────────────────────────────
// 封包接收解析 (由 interstellar_d 呼叫)
// ──────────────────────────────────────────────────────────
void receive_fs_session(mixed content) {
    string from_mudlib, to_mudlib, msg_type, session_id, payload;
    mapping data;

    if (mapp(content)) {
        // ── JSON 模式 ──
        data = content;
        from_mudlib = data["from"];
        to_mudlib   = data["to"];
        msg_type    = data["type"];
        session_id  = data["sid"];
        payload     = data["payload"];
    } else {
        // ── 舊版 Pipe 模式 (相容) ──
        string *parts = explode(content, "|");
        if (sizeof(parts) < 5) return;

        from_mudlib = trim(parts[1]);
        to_mudlib   = trim(parts[2]);
        msg_type    = trim(parts[3]);
        session_id  = trim(parts[4]);

        if (sizeof(parts) >= 6) {
            payload = implode(parts[5..], "|");
        }
    }

    if (to_mudlib != FS_MUDLIB_ID && to_mudlib != "*") return;
    
    // 🚀 關鍵修正：不處理自己廣播出去後又收回來的訊息
    if (from_mudlib == FS_MUDLIB_ID) return;
    
    // ── Client role ─────────────────────────────────────
    if (msg_type == "ack") {
        // 從所有在線玩家裡找有 ssh_pending == session_id 的那個
        object player = _find_player_by_temp("ssh_pending", session_id);
        if (player) {
            player->delete_temp("ssh_pending");
            player->set_temp("ssh_session_id", session_id);
            tell_object(player, HIM("[Fantasy Space] ") + "連線成功！你已登臨異界！\n\n");
            if (payload != "") tell_object(player, payload + "\n");
            player->sync_remote_ui();
        }
        return;
    }

    if (msg_type == "deny") {
        object player = _find_player_by_temp("ssh_pending", session_id);
        if (player) {
            player->delete_temp("ssh_pending");
            player->delete_temp("ssh_target");
            tell_object(player, RED("連線被拒絕：" + payload + "\n"));
            player->sync_remote_ui();
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
            player->sync_remote_ui();
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
        string p_id, p_name;
        if (mapp(data)) {
            p_id   = data["p_id"];
            p_name = data["p_name"];
        } else {
            string *user_info = explode(payload, "|");
            p_id   = (sizeof(user_info) > 0) ? user_info[0] : "guest";
            p_name = (sizeof(user_info) > 1) ? user_info[1] : "Guest";
        }

        object guest = clone_object("/std/guest.c");
        if (!guest) {
            send_msg(from_mudlib, ([
                "tag": "fs_session",
                "to": from_mudlib,
                "type": "deny",
                "sid": session_id,
                "payload": "無法建立訪客實體"
            ]));
            return;
        }

        guest->set_id(p_id);
        guest->set_name(p_name + "@" + from_mudlib);
        guest->set_temp("ssh_session_id",  session_id);
        guest->set_temp("ssh_remote_mud",  from_mudlib);

        string welcome = HIG("歡迎來到 " + FS_MUDLIB_ID + "！這是一個全新的世界。\n");
        send_msg(from_mudlib, ([
            "tag": "fs_session",
            "to": from_mudlib,
            "type": "ack",
            "sid": session_id,
            "payload": welcome
        ]));

        // 🚀 關鍵修正：由 Guest 自己發起 call_out，這樣 Driver 在執行時
        // 就會判定 Caller 是 Guest，進而自動帶上 PlayerContext！
        guest->call_out("do_guest_setup", 0);
        return;
    }

    if (msg_type == "input") {
        object guest = _find_guest_by_session(session_id);
        if (guest) {
            // 同理，由 Guest 發起指令執行的 call_out
            guest->call_out("do_remote_cmd", 0, payload);
        }
        return;
    }
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
