// /secure/interstellar_d.c
// 星際網路守護進程 (Interstellar Daemon)
// 負責處理跨伺服器 (P2P) 的通訊

#include "/include/ansi.h"

inherit "/std/object";

void create() {
    ::create();
}

// 當收到來自 P2P 網路的訊息時，由 Driver 呼叫此函式
void receive_p2p_message(string sender, string content, string type) {
    if (!content || content == "") return;
    
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
        if (u && userp(u)) {
            tell_object(u, full_msg);
        }
    }
}
