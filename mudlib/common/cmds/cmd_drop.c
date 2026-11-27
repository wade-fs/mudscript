// cmds/cmd_drop.c - 通用 drop 指令
#include "/include/ansi.h"
string *query_verbs()   { return ({ "drop" }); }
string query_category() { return "General"; }
int main(object me, string verb, string arg) {
    if (!arg || arg == "") { write("你想放下什麼？\n"); return 1; }
    string lower_arg = lower_case(arg);
    object *inv = all_inventory(me);
    for (int i = 0; i < sizeof(inv); i++) {
        object ob = inv[i];
        if (!ob->id(lower_arg) && !ob->id(arg)) continue;
        if (ob->query_no_drop()) {
            write(to_string(ob->query_short()) + " 無法被放下。\n");
            return 1;
        }
        object room = environment(me);
        move_object(ob, room);
        write("你放下了 " + to_string(ob->query_short()) + "。\n");
        tell_room(room, to_string(me->query_short()) + " 放下了 " + to_string(ob->query_short()) + "。\n", ({ me }));
        object ui = find_object("/daemon/ui_bridge_d.c");
        if (ui) ui->push_room_view(me);
        return 1;
    }
    write("你沒有帶著那個東西。\n");
    return 1;
}
