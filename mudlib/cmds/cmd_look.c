// mudlib/cmds/cmd_look.c
// 查看指令守護進程：look / l / examine / ex

inherit "/std/object";

int main(object me, string verb, string arg) {
    object here = environment(me);
    if (!here) {
        write(_t("void") + "\n");
        return 1;
    }

    if (!arg) {
        here->look_room(me);
        return 1;
    }

    // 處理方向縮寫
    switch(arg) {
        case "n": arg = "north"; break;
        case "s": arg = "south"; break;
        case "e": arg = "east";  break;
        case "w": arg = "west";  break;
        case "u": arg = "up";    break;
        case "d": arg = "down";  break;
    }

    // 檢查方向
    mapping exits = here->query_exits();
    if (exits && exits[arg]) {
        object dest = load_object(exits[arg]);
        if (dest) {
            write(select_lang(([
                "en": "You look to the " + arg + ":\n",
                "zh-TW": "你往 " + arg + " 看了看：\n",
                "zh-CN": "你往 " + arg + " 看了看：\n"
            ])));
            write("  " + dest->query_short() + "\n");
            return 1;
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

    // 看房間裝飾物
    string item_desc = here->look_at_item(arg);
    if (item_desc) {
        write(item_desc + "\n");
        return 1;
    }

    string not_found = _t("not_found");
    not_found = replace_string(not_found, "$arg", arg);
    write(not_found + "\n");
    return 1;
}

string *query_verbs() {
    return ({ "look", "l", "examine", "ex" });
}

string query_category() {
    return select_lang(([ "en": "View", "zh-TW": "查看", "zh-CN": "查看" ]));
}

string help() {
    return "【查看指令】\n" +
           "  look (l)              查看目前房間\n" +
           "  look <目標>           查看房間或背包中的物品\n" +
           "  look <方向>           查看該方向的情況\n" +
           "  examine (ex) <目標>   同 look，更仔細地檢視\n";
}
