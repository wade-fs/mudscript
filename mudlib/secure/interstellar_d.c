// /secure/interstellar_d.c
// 星際網路守護進程 (Interstellar Daemon)
// 負責處理跨伺服器 (P2P) 的通訊

#include "/include/ansi.h"

inherit "/std/object";

void create() {
    ::create();
}

// 🚀 強大且具相容性的接收函式
// 參數 1: 發送者名稱
// 參數 2: 訊息內容
// 參數 3: 訊息類型 (chat / system) - 預設為 chat
void receive_p2p_message(string sender, string content, string type) {
    if (!content || content == "") return;
    if (!sender || sender == "") sender = "Unknown";
    if (!type || type == "") type = "chat";
    
    string full_msg;
    
    if (type == "system") {
        full_msg = HIW("【星際廣播】") + content + "\n";
    } else {
        string prefix = HIM(select_lang(([ "en": "[Interstellar] ", "zh-TW": "【星際】", "zh-CN": "【星际】" ])));
        full_msg = prefix + sender + "：" + content + "\n";
    }
    
    object *users = users();
    if (!users) return;

    foreach (object u in users) {
        // 只要是正在連線的玩家都發送
        if (u && userp(u) && interactive(u)) {
            tell_object(u, full_msg);
        }
    }
}
