// /cmds/admin/cmd_edit.c
#include "/include/ansi.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (!wizardp(me)) return 0;
    if (!arg || arg == "") {
        write("Usage: edit <file>\n");
        return 1;
    }
    if (arg[0] != '/') arg = "/" + arg;

    // 🚀 使用驅動層提供的原始 Efun 名稱
    if (MUD_IS_WEB(me)) {
        write(HIW("Opening Web IDE for: ") + arg + "\n");
        MUD_REQUEST_EDIT(arg);
        return 1;
    }

    write("Sorry, this command only works in Web Client.\n");
    return 1;
}
string *query_verbs() { return ({ "edit" }); }
