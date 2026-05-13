// mudlib/cmds/cmd_inventory.c
// 物品指令守護進程：inventory / i / get / drop / wear / wield / remove

#include "/include/config.h"

int main(object me, string verb, string arg) {
    switch (verb) {
        case "inventory":
        case "i":
            return do_inventory(me, arg);
        case "get":
            return do_get(me, arg);
        case "drop":
            return do_drop(me, arg);
        case "wear":
            return do_wear(me, arg);
        case "wield":
            return do_wield(me, arg);
        case "remove":
            return do_remove(me, arg);
    }
    return 0;
}

int do_inventory(object me, string arg) {
    write("=== 背包 ===\n");
    mixed inv = all_inventory(me);
    if (sizeof(inv) == 0) {
        write("（空的）\n");
    } else {
        int i;
        for (i = 0; i < sizeof(inv); i++) {
            write("  " + inv[i]->query_short() + "\n");
        }
    }
    write("持有金幣：" + sprintf("%d", me->query_gold()) + "\n");
    return 1;
}

int do_get(object me, string arg) {
    if (!arg || arg == "") { write("撿起什麼？\n"); return 1; }
    object here = environment(me);
    object item = present(arg, here);
    if (!item) {
        write("這裡沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    if (living(item)) {
        write("你不能撿起活物。\n");
        return 1;
    }
    move_object(item, me);
    me->save(); // 立即存檔
    write("你撿起了 " + item->query_short() + "。\n");
    say(me->query_name() + " 撿起了 " + item->query_short() + "。\n");
    return 1;
}

int do_drop(object me, string arg) {
    if (!arg || arg == "") { write("丟下什麼？\n"); return 1; }
    object item = present(arg, me);
    if (!item) {
        write("你身上沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    object here = environment(me);
    move_object(item, here);
    me->save(); // 立即存檔
    write("你放下了 " + item->query_short() + "。\n");
    say(me->query_name() + " 放下了 " + item->query_short() + "。\n");
    return 1;
}

int do_wear(object me, string arg) {
    if (!arg || arg == "") { write("穿上什麼？\n"); return 1; }
    object item = present(arg, me);
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_ARMOUR) {
        write(item->query_short() + " 不是防具。\n");
        return 1;
    }
    if (!me->equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你穿上了 " + item->query_short() +
          "。（防禦力 +" + sprintf("%d", item->query_defence()) + "）\n");
    return 1;
}

int do_wield(object me, string arg) {
    if (!arg || arg == "") { write("裝備什麼武器？\n"); return 1; }
    object item = present(arg, me);
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_WEAPON) {
        write(item->query_short() + " 不是武器。\n");
        return 1;
    }
    if (!me->equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你裝備了 " + item->query_short() +
          "。（攻擊力 +" + sprintf("%d", item->query_attack()) + "）\n");
    return 1;
}

int do_remove(object me, string arg) {
    if (!arg || arg == "") { write("脫下什麼？\n"); return 1; }
    mixed slots = ({"weapon", "head", "body", "hands", "feet", "shield"});
    int i;
    for (i = 0; i < sizeof(slots); i++) {
        object e = me->query_equip(slots[i]);
        if (e && e->id(arg)) {
            me->unequip_slot(slots[i]);
            write("你脫下了 " + e->query_short() + "。\n");
            return 1;
        }
    }
    write("你沒有裝備叫「" + arg + "」的東西。\n");
    return 1;
}

string help() {
    return "【物品指令】\n" +
           "  inventory (i)   查看背包內容\n" +
           "  get <物品>      撿起物品\n" +
           "  drop <物品>     丟下物品\n" +
           "  wear <防具>     穿上防具\n" +
           "  wield <武器>    裝備武器\n" +
           "  remove <裝備>   卸下裝備\n";
}
