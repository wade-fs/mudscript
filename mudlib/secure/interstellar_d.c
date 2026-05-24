#include "/include/config.h"
// /secure/interstellar_d.c
// 星際網路守護進程 (Interstellar Daemon)
// 負責處理跨伺服器 (P2P) 的通訊，具備重複訊息過濾功能

#include "/include/ansi.h"

inherit "/std/object";

// 🚀 用於過濾重複訊息的緩存
mapping last_messages;

void create() {
    ::create();
    last_messages = ([]);
}

// 當收到來自 P2P 網路的訊息時，由 Driver 呼叫此函式
void receive_p2p_message(string sender, string content, string type) {
    if (!content || content == "") return;
    if (!sender || sender == "") sender = "Unknown";
    if (!type || type == "") type = "chat";

    // 🚀 關鍵：重複訊息過濾 (De-bounce)
    // 針對同一個發送者，若 2 秒內傳來完全相同的內容，則視為重複路由，予以忽略
    string msg_key = sender + ":" + content;
    int now = time();
    
    if (mapp(last_messages[msg_key]) && (now - last_messages[msg_key]["time"] < 2)) {
        // write("DEBUG: 攔截到重複星際訊息。\n");
        return;
    }
    
    // 更新緩存
    last_messages[msg_key] = ([ "time": now ]);
    
    // 定期清理緩存 (避免記憶體洩漏)
    if (sizeof(last_messages) > 100) {
        last_messages = ([]);
    }

    // ── Fantasy Space 跨服協議路由 ──────────────────────
    // 格式 1：fs_query|from_mudlib|to_mudlib|type|payload
    // 格式 2：fs_resp|from_mudlib|to_mudlib|type|payload...
    if (strsrch(content, "fs_query|") == 0 || strsrch(content, "fs_resp|") == 0) {
        object fs_d = load_object("/secure/fs_d.c");
        if (!fs_d) return;

        // 解析：type_tag|from|to|query_type|payload
        string tag = "";
        string from_mudlib = "";
        string to_mudlib = "";
        string query_type = "";
        string payload = "";

        // 使用一個更安全的字串拆分方法，避免 payload 內部有 |
        // 格式：tag|from|to|query_type|payload
        string *parts = explode(content, "|");
        if (sizeof(parts) < 4) return;
        
        tag = parts[0];
        from_mudlib = parts[1];
        to_mudlib = parts[2];
        query_type = parts[3];
        
        // 重新組裝 payload（若有多個 |）
        payload = "";
        for (int i = 4; i < sizeof(parts); i++) {
            payload += parts[i];
            if (i < sizeof(parts) - 1) payload += "|";
        }


        // 決定是否處理（to_mudlib 是本 mudlib 或廣播）
        if (tag == "fs_query" && (to_mudlib == FS_MUDLIB_ID || to_mudlib == "*")) {
            fs_d->handle_fs_query(from_mudlib, query_type, payload);
        } else if (tag == "fs_resp" && (to_mudlib == FS_MUDLIB_ID || to_mudlib == "*")) {
            fs_d->receive_fs_response(from_mudlib, query_type, payload);
        }
        return; // fs 訊息不走一般聊天流程
    }

    string full_msg;
    
    if (type == "system") {
        full_msg = HIW("【FS 廣播】") + content + "\n";
    } else {
        string prefix = HIM(select_lang(([ "en": "[Fantasy Space] ", "zh-TW": "【Fantasy Space】", "zh-CN": "【Fantasy Space】" ])));
        full_msg = prefix + sender + "：" + content + "\n";
    }
    
    object *users = users();
    if (!users) return;

    foreach (object u in users) {
        // 只發送給正在線上的真人玩家
        if (u && userp(u) && interactive(u)) {
            tell_object(u, full_msg);
        }
    }
}
