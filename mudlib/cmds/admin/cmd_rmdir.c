// /cmds/admin/cmd_rmdir.c

#include "/include/ansi.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") return 0;
    if (!arg || arg == "") { 
        write(select_lang(([
            "en": "Usage: rmdir <path>\n",
            "zh-TW": "用法：rmdir <路徑>\n",
            "zh-CN": "用法：rmdir <路径>\n"
        ])));
        return 1; 
    }
    if (arg[0] != '/') arg = "/" + arg;
    if (rmdir(arg)) write(HIG(select_lang(([
        "en": "Successfully removed directory: ",
        "zh-TW": "成功移除目錄：",
        "zh-CN": "成功移除目录："
    ]))) + arg + "\n");
    else write(HIR(select_lang(([
        "en": "Failed to remove directory (maybe not empty?).\n",
        "zh-TW": "移除目錄失敗（可能目錄非空？）。\n",
        "zh-CN": "移除目录失败（可能目录非空？）。\n"
    ]))));
    return 1;
}
string *query_verbs() { return ({ "rmdir" }); }
string query_category() { return "Admin"; }

string help() {
    return select_lang(([
        "en": "【Admin Command】\n  rmdir <path>   Remove an empty directory.\n",
        "zh-TW": "【管理指令】\n  rmdir <路徑>    移除空目錄。\n",
        "zh-CN": "【管理指令】\n  rmdir <路径>    移除空目录。\n"
    ]));
}
