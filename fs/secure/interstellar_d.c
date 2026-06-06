// /secure/interstellar_d.c
// 星際網路守護進程 (Interstellar Daemon)
// 負責處理跨伺服器 (P2P) 的通訊，具備重複訊息過濾功能

#include <globals.h>
#include <ansi.h>

#ifndef HIW
#define HIW(x) HIW + x + NOR
#endif

inherit F_CLEAN_UP;

// 🚀 用於過濾重複訊息的緩存
mapping last_messages;

void create() {
    last_messages = ([]);
}

// 當收到來自 P2P 網路的訊息時，由 Driver 呼叫此函式
void receive_p2p_message(string sender, string content, string type) {
    if (!content || content == "") return;
    if (!sender || sender == "") sender = "Unknown";
    if (!type || type == "") type = "chat";

    // 🚀 關鍵：重複訊息過濾 (De-bounce)
    string msg_key = sender + ":" + content;
    int now = time();
    
    // 如果 2 秒內收到重複訊息，過濾掉
    if (mapp(last_messages[msg_key]) && (now - last_messages[msg_key]["time"] < 2)) {
        return;
    }
    
    last_messages[msg_key] = ([ "time": now ]);
    
    if (sizeof(last_messages) > 200) {
        last_messages = ([]);
    }

    // ── Interstellar SSH Session 協議路由 ───────────────────
    if (strsrch(content, "fs_session|") == 0) {
        object ssh_d = load_object("/secure/ssh_d");
        if (ssh_d) {
            ssh_d->receive_fs_session(content);
        }
        return;
    }

    // ── Fantasy Space 跨服協議路由 ──────────────────────────
    if (strsrch(content, "fs_query|") == 0 || strsrch(content, "fs_resp|") == 0) {
        object fs_d = load_object("/secure/fs_d");
        if (fs_d) {
            string *parts = explode(content, "|");
            if (sizeof(parts) >= 4) {
                string tag = parts[0];
                string from_mudlib = parts[1];
                string to_mudlib = parts[2];
                string query_type = parts[3];
                string payload = implode(parts[4..], "|");

                string my_id = load_object("/secure/system_d")->query_mudlib_id();
                if (to_mudlib == my_id || to_mudlib == "*") {
                    if (tag == "fs_query")
                        fs_d->handle_fs_query(from_mudlib, query_type, payload);
                    else
                        fs_d->receive_fs_response(from_mudlib, query_type, payload);
                }
            }
        }
        return;
    }

    // ── Fantasy Space presence 協議路由 ─────────────────────
    if (strsrch(content, "fs_presence|") == 0) {
        object fs_d = load_object("/secure/fs_d");
        if (fs_d) fs_d->receive_p2p_message(sender, content, type);
        return;
    }

    // ── 廣播聊天 ──────────────────────────────────────────
    if (type == "chat") {
        string display_msg = sprintf(HIM("【星際廣播】%s：%s\n"), sender, content);
        foreach (object p in users()) {
            if (p->query("env/no_interstellar")) continue;
            tell_object(p, display_msg);
        }
    }
}
