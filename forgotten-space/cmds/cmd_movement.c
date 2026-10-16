// mudlib/cmds/cmd_movement.c
// 移動指令守護進程：north / south / east / west / up / down / go

inherit "/std/object";

int main(object me, string verb, string arg) {
    object here = environment(me);
    if (!here) {
        write(_t("void") + "\n");
        return 1;
    }

    string dir = arg;

    if (verb == "go") {
        if (!arg || arg == "") {
            write(_t("go_where") + "\n");
            return 1;
        }
        dir = arg;
    } else {
        mapping short_dirs = ([
            "ne": "northeast",
            "nw": "northwest",
            "se": "southeast",
            "sw": "southwest"
        ]);
        if (short_dirs[verb]) dir = short_dirs[verb];
        else dir = verb;
    }

    return here->do_go(dir);
}

string *query_verbs() {
    return ({ "north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest", "ne", "nw", "se", "sw", "up", "down", "go" });
}

string query_category() {
    return select_lang(([ "en": "Movement", "zh-TW": "移動", "zh-CN": "移动" ]));
}

string help() {
    return "【移動指令】\n" +
           "  north / south / east / west  往四個方向移動\n" +
           "  up / down                    往上 / 往下移動\n" +
           "  go <方向>                    明確移動，例如：go north\n";
}
