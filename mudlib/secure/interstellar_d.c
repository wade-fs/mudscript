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
