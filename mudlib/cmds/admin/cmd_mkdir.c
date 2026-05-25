// /cmds/admin/cmd_mkdir.c

#include "/include/ansi.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") return 0;
    if (!arg || arg == "") { 
        write(select_lang(([
            "en": "Usage: mkdir <path>\n",
            "zh-TW": "用法：mkdir <路徑>\n",
            "zh-CN": "用法：mkdir <路径>\n"
        ])));
        return 1; 
    }
    if (arg[0] != '/') arg = "/" + arg;
    if (mkdir(arg)) write(HIG(select_lang(([
        "en": "Successfully created directory: ",
        "zh-TW": "成功建立目錄：",
        "zh-CN": "成功建立目录："
    ]))) + arg + "\n");
    else write(HIR(select_lang(([
        "en": "Failed to create directory.\n",
        "zh-TW": "建立目錄失敗。\n",
        "zh-CN": "建立目录失败。\n"
    ]))));
    return 1;
}
string *query_verbs() { return ({ "mkdir" }); }
string query_category() { return "Admin"; }

string help() {
    return select_lang(([
        "en": "【Admin Command】\n  mkdir <path>   Create a new directory.\n",
        "zh-TW": "【管理指令】\n  mkdir <路徑>    建立新目錄。\n",
        "zh-CN": "【管理指令】\n  mkdir <路径>    建立新目录。\n"
    ]));
}
