// cmds/cmd_movement.c - 通用移動指令 (go)

#include "/include/ansi.h"
#include "/include/config.h"

string *query_verbs() {
    return ({ "go", "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "up", "down" });
}
string query_category() { return "Movement"; }

int main(object me, string verb, string arg) {
    string dir = (verb == "go" && arg) ? lower_case(arg) : lower_case(verb);
    if (verb == "go" && (!arg || arg == "")) {
        write("你想往哪個方向走？\n");
        return 1;
    }

    object room = environment(me);
    if (!room) {
        write("你不在任何地方。\n");
        return 1;
    }

    string dest = room->query_exit(dir);
    if (!dest) {
        write("那個方向沒有出口。\n");
        return 1;
    }

    object next = load_object(dest);
    if (!next) {
        write("無法前往（房間載入失敗）。\n");
        return 1;
    }

    string short_name = to_string(me->query_short());
    tell_room(room, short_name + " 往 " + dir + " 離開了。\n", ({ me }));

    move_object(me, next);

    tell_room(next, short_name + " 從遠處走來。\n", ({ me }));

    me->do_look();
    me->mark_explored(base_name(next));

    object qed = find_object("/daemon/quest_engine_d.c");
    if (qed) qed->trigger_quest_event(me, "enter_room", ([ "room": dest ]));

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (!ui) ui = load_object("/daemon/ui_bridge_d.c");
    if (ui) ui->push_room_view(me);

    return 1;
}
