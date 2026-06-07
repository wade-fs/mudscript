// /cmds/admin/cmd_edit.c
#include "/include/ansi.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!wizardp(me)) return 0;
    if (!arg || arg == "") {
        write(select_lang(([ "en": "Usage: edit <file>
", "zh-TW": "用法：edit <檔案>
", "zh-CN": "用法：edit <文件>
" ])));
        return 1;
    }
    if (arg[0] != '/') arg = "/" + arg;
    request_web_edit(arg);
    return 1;
}
string *query_verbs() { return ({ "edit", "wed" }); }
