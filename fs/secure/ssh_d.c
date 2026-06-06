// /secure/ssh_d.c
// SSH Daemon (Interstellar Network SSH-like Sessions)

#include <globals.h>
#include <ansi.h>

#ifndef HIM
#define HIM(x) HIM + x + NOR
#endif

inherit F_CLEAN_UP;

mapping client_sessions;
mapping server_sessions;

void create() {
    client_sessions = ([]);
    server_sessions = ([]);
}

string query_my_id() {
    return load_object("/secure/system_d")->query_mudlib_id();
}

string generate_uuid() {
    return sprintf("%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
        random(65536), random(65536),
        random(65536),
        random(65536),
        random(65536),
        random(65536), random(65536), random(65536));
}

void send_msg(string target_mudlib, string msg) {
    p2p_broadcast(msg, target_mudlib);
}

// ── CLIENT ROLE ──────────────────────────────────────
void start_session(object player, string target_mudlib) {
    if (!player || !userp(player)) return;

    string session_id = generate_uuid();
    client_sessions[session_id] = player;

    player->set_temp("ssh_pending", session_id);
    player->set_temp("ssh_target", target_mudlib);
    
    tell_object(player, HIM("[Fantasy Space] ") + "正在請求連線至 " + target_mudlib + "...\n");

    string payload = player->query("id") + "|" + player->query("name");
    string msg = "fs_session|" + query_my_id() + "|" + target_mudlib + "|connect|" + session_id + "|" + payload;
    send_msg(target_mudlib, msg);
}

void client_send_input(object player, string cmd) {
    string session_id = player->query_temp("ssh_session_id");
    string target = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    string msg = "fs_session|" + query_my_id() + "|" + target + "|input|" + session_id + "|" + cmd;
    send_msg(target, msg);
}

void client_send_disconnect(object player) {
    string session_id = player->query_temp("ssh_session_id");
    if (!session_id) session_id = player->query_temp("ssh_pending");
    string target = player->query_temp("ssh_target");
    if (!session_id || !target) return;

    string msg = "fs_session|" + query_my_id() + "|" + target + "|disconnect|" + session_id + "|Client closed";
    send_msg(target, msg);

    m_delete(client_sessions, session_id);
    player->delete_temp("ssh_session_id");
    player->delete_temp("ssh_pending");
    player->delete_temp("ssh_target");
    tell_object(player, HIM("[Fantasy Space] ") + "連線已關閉，你回到了現實。\n");
}

// ── SERVER ROLE ──────────────────────────────────────
void server_send_output(string target_mudlib, string session_id, string text) {
    string msg = "fs_session|" + query_my_id() + "|" + target_mudlib + "|output|" + session_id + "|" + text;
    send_msg(target_mudlib, msg);
}

void server_send_disconnect(string target_mudlib, string session_id, string reason) {
    string msg = "fs_session|" + query_my_id() + "|" + target_mudlib + "|disconnect|" + session_id + "|" + reason;
    send_msg(target_mudlib, msg);
    
    object guest = server_sessions[session_id];
    if (guest) {
        destruct(guest);
    }
    m_delete(server_sessions, session_id);
}

void receive_fs_session(string content) {
    string *parts = explode(content, "|");
    if (sizeof(parts) < 5) return;

    string from_mudlib = parts[1];
    string to_mudlib   = parts[2];
    string msg_type    = parts[3];
    string session_id  = parts[4];
    string payload     = (sizeof(parts) > 5) ? implode(parts[5..], "|") : "";

    if (to_mudlib != query_my_id()) return;

    switch(msg_type) {
        case "connect": {
            // TODO: 建立 Guest 帳號
            server_send_output(from_mudlib, session_id, "Welcome to " + query_my_id() + "! (Guest mode)\n");
            break;
        }
        case "input": {
            object guest = server_sessions[session_id];
            if (guest) {
                // TODO: 執行指令
            }
            break;
        }
        case "output": {
            object player = client_sessions[session_id];
            if (player) tell_object(player, payload);
            break;
        }
        case "disconnect": {
            object player = client_sessions[session_id];
            if (player) {
                player->delete_temp("ssh_session_id");
                tell_object(player, HIM("[Fantasy Space] ") + "遠端主機已斷開連線。\n");
            }
            m_delete(client_sessions, session_id);
            break;
        }
    }
}
