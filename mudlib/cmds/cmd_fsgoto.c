// /cmds/cmd_fsgoto.c
// 透過傳送門前往遠端 mudlib

#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：fsgoto <mudlib_id>\n");
        return 1;
    }

    // 🚀 特化處理：去除雙引號，並將空格轉換為點（ID 格式）
    arg = trim(arg);
    if (strlen(arg) > 2 && arg[0] == '"' && arg[strlen(arg)-1] == '"') {
        arg = substr(arg, 1, strlen(arg)-2);
    }
    arg = replace_string(arg, " ", ".");

    object fs_d = load_object("/secure/fs_d.c");
    if (!fs_d) {
        write("系統錯誤：無法載入跨服守護進程。\n");
        return 1;
    }

    string res = fs_d->init_fsgoto(me, arg);
    if (res != "") write(res);

    return 1;
}

string help() {
    return "【指令】\n  fsgoto <mudlib_id>   透過星際傳送門前往已加入的遠端伺服器。\n";
}
