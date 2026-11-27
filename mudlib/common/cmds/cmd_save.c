// cmds/cmd_save.c - 通用存檔指令
#include "/include/ansi.h"
string *query_verbs()   { return ({ "save" }); }
string query_category() { return "System"; }
int main(object me, string verb, string arg) {
    me->do_save();
    write("{GRN}存檔完成。{NOR}\n");
    return 1;
}
