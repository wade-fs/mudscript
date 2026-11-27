// cmds/cmd_say.c - 通用說話指令
#include "/include/ansi.h"
string *query_verbs()   { return ({ "say" }); }
string query_category() { return "Communication"; }
int main(object me, string verb, string arg) {
    if (!arg || arg == "") { write("你想說什麼？\n"); return 1; }
    string msg = to_string(me->query_short()) + " 說：「" + arg + "」\n";
    write("{GRN}你說：「" + arg + "」{NOR}\n");
    if (environment(me)) tell_room(environment(me), "{GRN}" + msg + "{NOR}", ({ me }));
    return 1;
}
