// /secure/interstellar_d.c
// 星際網路守護進程 (Interstellar Daemon)
// 負責處理跨伺服器 (P2P) 的通訊

#include "/include/ansi.h"

inherit "/std/object";

void create() {
    ::create();
}

// 當收到來自 P2P 網路的訊息時，由 Driver 呼叫此函式
void receive_p2p_message(string sender, string content) {
    if (!content || content == "") return;
    
    string full_msg = HIM("【星際】") + sender + "：" + content + "\n";
    
    object *users = users();
    foreach (object u in users) {
        if (u && is_interactive(u)) {
            tell_object(u, full_msg);
        }
    }
}
