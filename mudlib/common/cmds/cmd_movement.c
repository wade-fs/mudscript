// cmds/cmd_movement.c - 共用移動指令 (go / 方向縮寫)

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

string *query_verbs() {
    return ({ "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "ne", "nw", "se", "sw", "up", "down", "enter", "out", "go" });
}

string query_category() {
    return select_lang(([ "en": "Movement", "zh-TW": "移動", "zh-CN": "移动" ]));
}

int main(object me, string verb, string arg) {
    object room = environment(me);
    if (!room) {
        write(_t("void") + "\n");
        return 1;
    }

    string dir;
    if (verb == "go") {
        if (!arg || arg == "") {
            write(_t("go_where") + "\n");
            return 1;
        }
        dir = lower_case(trim(arg));
    } else {
        mapping short_dirs = ([
            "ne": "northeast",
            "nw": "northwest",
            "se": "southeast",
            "sw": "southwest"
        ]);
        string lv = lower_case(verb);
        dir = short_dirs[lv] ? short_dirs[lv] : lv;
    }

    // 若房間實作 do_go()（如 fsmud / forgotten-space 的完整房間邏輯），直接委派
    if (function_exists("do_go", room)) {
        return room->do_go(dir);
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

    if (function_exists("do_look", me)) me->do_look();
    if (function_exists("mark_explored", me)) me->mark_explored(base_name(next));

    object qed = find_object(QUEST_ENGINE_D);
    if (qed) qed->trigger_quest_event(me, "enter_room", ([ "room": dest ]));

    object ui = find_object(UI_BRIDGE_D);
    if (!ui) ui = load_object(UI_BRIDGE_D);
    if (ui) ui->push_room_view(me);

    return 1;
}

string help() {
    return "【移動指令】\n" +
           "  north / south / east / west  往四個方向移動\n" +
           "  up / down / enter / out      上下或進出\n" +
           "  go <方向>                    明確移動，例如：go north\n";
}
