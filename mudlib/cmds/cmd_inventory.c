// mudlib/cmds/cmd_inventory.c
// 物品指令模組：inventory / i / get / drop / wear / wield

#include "/include/config.h"

void cmd_inventory_setup() {
    add_action("do_inventory", "inventory");
    add_action("do_inventory", "i");
    add_action("do_get",       "get");
    add_action("do_drop",      "drop");
    add_action("do_wear",      "wear");
    add_action("do_wield",     "wield");
    add_action("do_remove",    "remove");
}

int do_inventory(string arg) {
    write("=== 背包 ===\n");
    mixed inv = all_inventory(this_object());
    if (sizeof(inv) == 0) {
        write("（空的）\n");
    } else {
        int i;
        for (i = 0; i < sizeof(inv); i++) {
            write("  " + inv[i]->query_short() + "\n");
        }
    }
    write("持有金幣：" + sprintf("%d", query_gold()) + "\n");
    return 1;
}

int do_get(string arg) {
    if (!arg) { write("撿起什麼？\n"); return 1; }
    object here = environment(this_object());
    object item = present(arg, here);
    if (!item) {
        write("這裡沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    if (living(item)) {
        write("你不能撿起活物。\n");
        return 1;
    }
    move_object(item, this_object());
    write("你撿起了 " + item->query_short() + "。\n");
    say(query_name() + " 撿起了 " + item->query_short() + "。\n");
    return 1;
}

int do_drop(string arg) {
    if (!arg) { write("丟下什麼？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) {
        write("你身上沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    object here = environment(this_object());
    move_object(item, here);
    write("你放下了 " + item->query_short() + "。\n");
    say(query_name() + " 放下了 " + item->query_short() + "。\n");
    return 1;
}

int do_wear(string arg) {
    if (!arg) { write("穿上什麼？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_ARMOUR) {
        write(item->query_short() + " 不是防具。\n");
        return 1;
    }
    if (!equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你穿上了 " + item->query_short() +
          "。（防禦力 +" + sprintf("%d", item->query_defence()) + "）\n");
    return 1;
}

int do_wield(string arg) {
    if (!arg) { write("裝備什麼武器？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_WEAPON) {
        write(item->query_short() + " 不是武器。\n");
        return 1;
    }
    if (!equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你裝備了 " + item->query_short() +
          "。（攻擊力 +" + sprintf("%d", item->query_attack()) + "）\n");
    return 1;
}

int do_remove(string arg) {
    if (!arg) { write("脫下什麼？\n"); return 1; }
    mixed slots = ({"weapon", "head", "body", "hands", "feet", "shield"});
    int i;
    for (i = 0; i < sizeof(slots); i++) {
        object e = query_equip(slots[i]);
        if (e && e->id(arg)) {
            unequip_slot(slots[i]);
            write("你脫下了 " + e->query_short() + "。\n");
            return 1;
        }
    }
    write("你沒有裝備叫「" + arg + "」的東西。\n");
    return 1;
}
