#include "/include/config.h"
#include "/include/ansi.h"

// /std/guest.c
// 遠端訪客 (Guest) 的虛擬實體

inherit "/std/user";

string remote_mudlib;
string session_id;

void create() {
    ::create();
    set_name("未知訪客");
    enable_commands();
}

void set_temp(string key, mixed val) {
    ::set_temp(key, val);
    if (key == "ssh_session_id") session_id = val;
    if (key == "ssh_remote_mud") remote_mudlib = val;
}

// 攔截所有發送給此訪客的訊息，轉發回來源機器
void catch_tell(string msg) {
    if (!msg || msg == "") return;
    if (!session_id || !remote_mudlib) return;

    object ssh_d = find_object("/secure/ssh_d.c");
    if (ssh_d) {
        ssh_d->server_send_output(remote_mudlib, session_id, msg);
    }
}

// 覆寫存檔機制：訪客離開時不存檔
int save() {
    return 1; // 假裝存檔成功
}

void quit() {
    object ssh_d = find_object("/secure/ssh_d.c");
    if (ssh_d) {
        ssh_d->server_send_disconnect(remote_mudlib, session_id, "Guest quit");
    }
    
    tell_room(environment(this_object()), query_name() + "化作一道光芒消失了。\n", ({ this_object() }));
    destruct(this_object());
}

// 指令處理 (接收到來自 ssh_d 的 input 時，會呼叫此函式)
// 我們直接讓它繼承 user.c 的 process_input，它會處理所有正常指令
