// /cmds/cmd_perform.c
// 施展特殊招式指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("你要施展什麼招式？用法：perform <招式ID> [目標]\n");
        return 1;
    }

    string sid, target;
    int sp = strsrch(arg, " ");
    if (sp == -1) {
        sid = arg;
        target = "";
    } else {
        sid = substr(arg, 0, sp);
        target = substr(arg, sp + 1, strlen(arg) - sp - 1);
    }

    return load_object("/secure/combat_d.c")->do_perform(me, sid, target);
}

string help() {
    return "【戰鬥指令】\n" +
           "  perform <招式> [目標]    施展職業專屬的強大招式或法術。\n" +
           "  (例如：perform bash, perform fireball, perform heal)\n";
}
