// mudlib/cmds/cmd_look.c
// 查看指令模組：look / l / examine / ex

void cmd_look_setup() {
    add_action("do_look",    "look");
    add_action("do_look",    "l");
    add_action("do_examine", "examine");
    add_action("do_examine", "ex");
}

int do_look(string arg) {
    object here = environment(this_object());
    if (!here) {
        write("你飄浮在虛空中。\n");
        return 1;
    }

    if (!arg) {
        // 印出傳統的文字描述
        here->look_room();
        
        // 🚀 新增：發送小地圖的 JSON 資料給前端
        mapping map_data = ([
            "center_name": here->query_short(),
            "exits": keys(here->query_exits())
        ]);
        write(sprintf("{\"ui\": \"minimap\", \"data\": %s}", json_encode(map_data)));
        
        return 1;
    }

    // 看房間裡的物件
    object target = present(arg, here);
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看背包裡的物件
    target = present(arg, this_object());
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看房間裝飾物
    string item_desc = here->look_at_item(arg);
    if (item_desc != "") {
        write(item_desc + "\n");
        return 1;
    }

    write("你看不到叫「" + arg + "」的東西。\n");
    return 1;
}

int do_examine(string arg) {
    return do_look(arg);
}
