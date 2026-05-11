// mudlib/cmds/cmd_look.c
// 查看指令守護進程：look / l / examine / ex

int main(object me, string arg) {
    object here = environment(me);
    if (!here) {
        write("你飄浮在虛空中。\n");
        return 1;
    }

    if (!arg || arg == "") {
        here->look_room();
        return 1;
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

    write("你看不到叫「" + arg + "」的東西。\n");
    return 1;
}

string help() {
    return "【查看指令】\n" +
           "  look (l)              查看目前房間\n" +
           "  look <目標>           查看房間或背包中的物品\n" +
           "  examine (ex) <目標>   同 look，更仔細地檢視\n";
}
