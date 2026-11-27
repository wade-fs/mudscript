// cmds/cmd_look.c - 通用 look 指令

#include "/include/ansi.h"
#include "/include/config.h"

string *query_verbs()   { return ({ "look", "l" }); }
string query_category() { return "General"; }

int main(object me, string verb, string arg) {
    object room = environment(me);
    if (!room) {
        write("你不在任何地方。\n");
        return 1;
    }

    if (!arg || arg == "") {
        me->do_look();

        object ui = find_object("/daemon/ui_bridge_d.c");
        if (!ui) ui = load_object("/daemon/ui_bridge_d.c");
        if (ui) ui->push_room_view(me);
        return 1;
    }

    string lower_arg = lower_case(arg);

    string dest = room->query_exit(lower_arg);
    if (dest) {
        object next = load_object(dest);
        if (next) {
            write("{CYN}往 " + lower_arg + " 方向：{NOR} " + to_string(next->query_short()) + "\n");
            return 1;
        }
    }

    object *inv = all_inventory(room);
    for (int i = 0; i < sizeof(inv); i++) {
        object ob = inv[i];
        if (ob->id(lower_arg)) {
            write("{HIW}" + to_string(ob->query_short()) + "{NOR}\n");
            write(to_string(ob->query_long()) + "\n");
            return 1;
        }
    }

    object *my_inv = all_inventory(me);
    for (int i = 0; i < sizeof(my_inv); i++) {
        object ob = my_inv[i];
        if (ob->id(lower_arg)) {
            write("{HIW}" + to_string(ob->query_short()) + "{NOR}\n");
            write(to_string(ob->query_long()) + "\n");
            return 1;
        }
    }

    if (function_exists("query_item_ids", room)) {
        mapping items = room->query_item_ids();
        if (mapp(items) && items[lower_arg]) {
            write(to_string(select_lang(items[lower_arg])) + "\n");
            return 1;
        }
        if (mapp(items) && items[arg]) {
            write(to_string(select_lang(items[arg])) + "\n");
            return 1;
        }
    }

    write("你沒有看到那個東西。\n");
    return 1;
}
