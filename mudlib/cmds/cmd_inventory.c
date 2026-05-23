// mudlib/cmds/cmd_inventory.c
// 物品指令守護進程：inventory / i / get / drop / wear / wield / remove

#include "/include/config.h"
#include "/include/ansi.h"

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
        case "appraise":
        case "identify":
            return do_appraise(me, arg);
    }
    return 0;
}

int do_inventory(object me, string arg) {
    object *inv = all_inventory(me);
    if (!inv || sizeof(inv) == 0) {
        write("你身上沒有任何東西。\n");
        return 1;
    }

    write("你身上帶著以下物品：\n");
    for (int i = 0; i < sizeof(inv); i++) {
        write("  " + inv[i]->query_short() + "\n");
    }
    return 1;
}

int do_get(object me, string arg) {
    if (!arg) { write("撿起什麼？\n"); return 1; }

    object container = environment(me);
    string item_id = arg;

    // 支援 get item from container
    if (strsrch(arg, " from ") != -1) {
        string *parts = explode(arg, " from ");
        item_id = parts[0];
        string cont_id = parts[1];
        
        container = present(cont_id, environment(me));
        if (!container) container = present(cont_id, me);
        
        if (!container) {
            write("這裡沒有叫「" + cont_id + "」的容器。\n");
            return 1;
        }
        if (container->query_closed()) {
            write(container->query_short() + " 是關著的。\n");
            return 1;
        }
    }

    object item = present(item_id, container);
    if (!item) {
        string loc_name = "這裡";
        if (container != environment(me)) {
            loc_name = container->query_short();
        }
        write(loc_name + " 沒有叫「" + item_id + "」的東西。\n");
        return 1;
    }

    if (living(item)) {
        write("你不能撿起活物。\n");
        return 1;
    }

    if (item->query_no_get()) {
        write(item->query_short() + " 太重了，或者是被固定住了，你拿不起來。\n");
        return 1;
    }

    // 🚀 新增：檢查屍體歸屬 (Loot Binding)
    string owner_tid = container->query_team_owner();
    if (owner_tid != "") {
        object my_leader = me->query_leader();
        string my_tid;
        if (my_leader) {
            my_tid = my_leader->get_id();
        } else {
            my_tid = me->get_id();
        }
        
        if (my_tid != owner_tid) {
            write(HIR("這具屍體的戰利品暫時受保護，你目前無法拿取。\n"));
            return 1;
        }
    }

    if (!me->can_receive(item)) {
        write("你的背包裝不下了。\n");
        return 1;
    }

    // 🚀 跑屍機制：如果從自己的屍體撿東西
    if (strsrch(object_name(container), "/std/corpse.c") != -1) {
        mapping penalty = container->query_penalty_data();
        if (penalty && penalty["owner"] == me->get_id()) {
            int back_exp = penalty["exp"] / 2;
            int back_pot = penalty["pot"] / 2;
            if (back_exp > 0 || back_pot > 0) {
                me->gain_exp(back_exp);
                me->gain_potential(back_pot);
                write(HIY("✨ 你取回了自己的遺物，靈魂感到一陣充實，恢復了部分損失的經驗與潛能。\n"));
                // 清除屍體上的懲罰紀錄，避免重複領取
                container->set_penalty_data(([]));
            }
        }
    }

    // 🚀 新增：錢袋處理
    if (item->query_money_value() > 0) {
        int m = item->query_money_value();
        me->add_money(m);
        write(HIG("你打開了錢袋，獲得了 " + m + " 銅幣。\n"));
        destruct(item);
        return 1;
    }

    if (move_object(item, me)) {
        me->save(); // 立即存檔
        string from_name = "地上";
        if (container != environment(me)) {
            from_name = container->query_short();
        }
        write("你從 " + from_name + " 撿起了 " + item->query_short() + "。\n");
        say(me->query_name() + " 撿起了 " + item->query_short() + "。\n");
    } else {
        write("你無法拿走這個物品。\n");
    }
    return 1;
}

int do_drop(object me, string arg) {
    if (!arg) { write("丟下什麼？\n"); return 1; }
    object item = present(arg, me);
    if (!item) {
        write("你身上沒有叫「" + arg + "」的東西。\n");
        return 1;
    }

    if (item->query_no_drop()) {
        write(item->query_short() + " 似乎黏在你的手上了，丟不掉！\n");
        return 1;
    }

    object here = environment(me);
    if (move_object(item, here)) {
        me->save(); // 立即存檔
        write("你放下了 " + item->query_short() + "。\n");
        say(me->query_name() + " 放下了 " + item->query_short() + "。\n");
    } else {
        write("你現在沒辦法丟下這個東西。\n");
    }
    return 1;
}

int do_wear(object me, string arg) {
    if (!arg) { write("穿上什麼？\n"); return 1; }
    object item = present(arg, me);
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    
    if (item->query_item_type() != ITEM_ARMOUR) {
        write(item->query_short() + " 不是防具。\n");
        return 1;
    }

    if (me->query_level() < item->query_level_req()) {
        write("你的等級不足，無法裝備 " + item->query_short() + 
              " (需要等級 " + item->query_level_req() + ")。\n");
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
    if (!arg) { write("裝備什麼武器？\n"); return 1; }
    object item = present(arg, me);
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    
    if (item->query_item_type() != ITEM_WEAPON) {
        write(item->query_short() + " 不是武器。\n");
        return 1;
    }

    if (me->query_level() < item->query_level_req()) {
        write("你的等級不足，無法裝備 " + item->query_short() + 
              " (需要等級 " + item->query_level_req() + ")。\n");
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
    if (!arg) { write("脫下什麼？\n"); return 1; }
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

int do_appraise(object me, string arg) {
    if (!arg) { write("鑑定什麼？\n"); return 1; }
    object item = present(arg, me);
    if (!item) item = present(arg, environment(me));
    if (!item) { write("找不到「" + arg + "」。\n"); return 1; }

    write("你仔細觀察 " + item->query_short() + "...\n");
    
    if (item->query_identified() == 0) {
        write("這件物品尚未被鑑定，你看不出它的具體深淺。\n");
        return 1;
    }

    string desc = "【物品資訊：" + item->query_name() + "】\n";
    desc += "  種類：" + item->query_item_type() + "\n";
    desc += "  重量：" + sprintf("%d", item->query_weight()) + "g\n";
    desc += "  價值：" + sprintf("%d", item->query_value()) + " 金幣\n";
    desc += "  耐久：" + sprintf("%d/%d", item->query_durability(), item->query_max_durability()) + "\n";
    desc += "  需求等級：" + sprintf("%d", item->query_level_req()) + "\n";

    if (item->query_item_type() == ITEM_WEAPON) {
        desc += "  攻擊力：+" + sprintf("%d", item->query_attack()) + "\n";
        string attr = item->query_element();
        if (attr == "") attr = "無";
        desc += "  屬性：" + attr + "\n";
    } else if (item->query_item_type() == ITEM_ARMOUR) {
        desc += "  防禦力：+" + sprintf("%d", item->query_defence()) + "\n";
        desc += "  部位：" + item->query_slot_name() + "\n";
    }

    write(desc);
    return 1;
}

string help() {
    return "【物品指令】\n" +
           "  inventory (i)   查看背包內容\n" +
           "  get <物品>      撿起物品\n" +
           "  drop <物品>     丟下物品\n" +
           "  wear <防具>     穿上防具\n" +
           "  wield <武器>    裝備武器\n" +
           "  remove <裝備>   卸下裝備\n" +
           "  appraise <物品> 鑑定並查看詳細屬性\n";
}
