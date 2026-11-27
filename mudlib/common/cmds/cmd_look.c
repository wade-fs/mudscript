// cmds/cmd_look.c - 共用查看指令 (look / l / examine / ex)

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

string *query_verbs() { return ({ "look", "l", "examine", "ex" }); }
string query_category() {
    return select_lang(([ "en": "View", "zh-TW": "查看", "zh-CN": "查看" ]));
}

int main(object me, string verb, string arg) {
    object here = environment(me);
    if (!here) {
        write(_t("void") + "\n");
        return 1;
    }

    if (!arg || arg == "") {
        if (function_exists("look_room", here)) {
            here->look_room(me);
        } else {
            if (function_exists("do_look", me)) me->do_look();
            object ui = find_object(UI_BRIDGE_D);
            if (!ui) ui = load_object(UI_BRIDGE_D);
            if (ui) ui->push_room_view(me);
        }
        return 1;
    }

    string orig_arg = arg;
    arg = lower_case(arg);

    // 方向正規化與中文支援
    mapping dir_map = ([
        "n": "north", "north": "north", "北": "north", "北方": "north",
        "s": "south", "south": "south", "南": "south", "南方": "south",
        "e": "east",  "east": "east",   "東": "east",  "東方": "east",
        "w": "west",  "west": "west",   "西": "west",  "西方": "west",
        "ne": "northeast", "northeast": "northeast", "東北": "northeast", "東北方": "northeast",
        "nw": "northwest", "northwest": "northwest", "西北": "northwest", "西北方": "northwest",
        "se": "southeast", "southeast": "southeast", "東南": "southeast", "東南方": "southeast",
        "sw": "southwest", "southwest": "southwest", "西南": "southwest", "西南方": "southwest",
        "u": "up",    "up": "up",       "上": "up",    "上方": "up",
        "d": "down",  "down": "down",   "下": "down",  "下方": "down"
    ]);

    string dir = dir_map[arg];
    if (dir) {
        mixed exits = here->query_exits();
        if (mapp(exits)) {
            mixed dest_path = exits[dir];
            if (dest_path) {
                object dest = load_object(dest_path);
                if (dest) {
                    write(select_lang(([
                        "en":    "You look to the " + dir + ":\n",
                        "zh-TW": "你往 " + dir + " 看了看：\n",
                        "zh-CN": "你往 " + dir + " 看了看：\n"
                    ])));
                    write("  " + dest->query_short() + "\n");
                    return 1;
                } else {
                    write(select_lang(([
                        "en":    "You look to the " + dir + ", but it is too dark to see anything.\n",
                        "zh-TW": "你往 " + dir + " 看了看，但那裡太暗了，什麼都看不清楚。\n",
                        "zh-CN": "你往 " + dir + " 看了看，但那里太暗了，什么都看不清楚。\n"
                    ])));
                    return 1;
                }
            }
        }
    }

    // 看房間裡的物件
    object target = present(arg, here);
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看背包裡的物件
    target = present(arg, me);
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看房間裝飾物 (傳統 room.c)
    if (function_exists("look_at_item", here)) {
        string item_desc = here->look_at_item(arg);
        if (item_desc && item_desc != "") {
            write(item_desc + "\n");
            return 1;
        }
    }

    // 看 JSON 房間裝飾物 (json_room.c)
    if (function_exists("query_item_ids", here)) {
        mapping items = here->query_item_ids();
        if (mapp(items)) {
            if (items[arg]) {
                write(to_string(select_lang(items[arg])) + "\n");
                return 1;
            }
            if (items[orig_arg]) {
                write(to_string(select_lang(items[orig_arg])) + "\n");
                return 1;
            }
        }
    }

    string not_found = _t("not_found");
    if (not_found && not_found != "not_found") {
        not_found = replace_string(not_found, "$arg", arg);
        write(not_found + "\n");
    } else {
        write("你沒有看到那個東西。\n");
    }
    return 1;
}

string help() {
    return "【查看指令】\n" +
           "  look (l)              查看目前房間\n" +
           "  look <目標>           查看房間或背包中的物品\n" +
           "  look <方向>           查看該方向的情況\n" +
           "  examine (ex) <目標>   同 look，更仔細地檢視\n";
}
