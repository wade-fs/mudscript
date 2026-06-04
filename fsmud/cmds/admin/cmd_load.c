// /cmds/admin/cmd_load.c
// 載入物件指令：load <路徑>

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        return 0;
    }

    if (!arg || arg == "") {
        write("用法：load <檔案路徑>\n");
        return 1;
    }

    if (arg[0] != '/') arg = "/" + arg;
    
    object ob = load_object(arg);
    if (ob) {
        write(HIG("物件載入成功：") + arg + "\n");
    } else {
        write(HIR("物件載入失敗：") + arg + "\n");
    }

    return 1;
}

string *query_verbs() { return ({ "load" }); }
string query_category() { return "Admin"; }

string help() {
    return "【管理指令】\n" +
           "  load <路徑>    編譯並載入指定的 LPC 檔案至記憶體（不進行複製）。\n";
}
