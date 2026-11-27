// cmds/cmd_quit.c - 通用 quit 指令

#include "/include/ansi.h"

string *query_verbs()   { return ({ "quit" }); }
string query_category() { return "System"; }

int main(object me, string verb, string arg) {
    if (environment(me)) {
        me->set_last_location(base_name(environment(me)));
        tell_room(environment(me), to_string(me->query_short()) + " 離線了。\n", ({ me }));
    }
    me->do_save();
    write("再見！下次見。\n");
    destruct(me);
    return 1;
}
