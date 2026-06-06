// /cmds/std/fsgoto.c
// 跨服傳送：fsgoto <mudlib_id>

#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    arg = trim(arg);

    string my_id = load_object("/secure/system_d")->query_mudlib_id();

    if (!arg || arg == "") {
        write(HIW("【Fantasy Space 跨服傳送】\n") +
              "用法：fsgoto <mudlib_id>\n\n" +
              "  抵達後，你的所有指令都在遠端執行，就像轉世投胎。\n" +
              "  輸入 " + CYN("fsleave") + " 返回本機。\n" +
              "  輸入 " + CYN("!<指令>") + " 強制在本機執行。\n\n" +
              "  使用 " + CYN("fslist") + " 查詢可抵達的星際節點。\n");
        return 1;
    }

    if (arg == my_id) {
        write("你已經在本機伺服器了。\n");
        return 1;
    }

    object ssh_d = load_object("/secure/ssh_d");
    if (!ssh_d) {
        write(RED("系統錯誤：無法載入 ssh_d。\n"));
        return 1;
    }

    ssh_d->start_session(me, arg);
    return 1;
}

string help() {
    return HIW("【fsgoto】跨服傳送\n") +
           "  fsgoto <mudlib_id>   連接到指定的遠端伺服器。\n" +
           "  進入後所有指令在遠端執行，fsleave 返回本機。\n";
}
