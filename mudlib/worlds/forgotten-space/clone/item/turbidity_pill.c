// clone/item/turbidity_pill.c
// 杏林醫館・清心散 (清除紅塵濁氣專用藥劑)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("清心散", ({ "turbidity pill", "pill", "qingxin san", "清心散", "藥散" }));
    set_short(HIG "杏林清心散" NOR);
    set_long("杏林醫館館主白先生以青河洗靈草、薄荷腦配製的專用解濁藥粉。\n"
             "散發著極其清冽的苦草氣息。服用 (drink/use pill) 可迅速滌蕩心神濁障，淨化 20 點紅塵濁氣。\n");
    set_weight(50);
    set_value(50);
    set("is_consumable", 1);
}

void init() {
    ::init();
    add_action("do_consume", "use");
    add_action("do_consume", "drink");
    add_action("do_consume", "eat");
    add_action("do_consume", "服");
}

int do_consume(string arg) {
    object me = this_player();
    if (!arg || (arg != "pill" && arg != "turbidity pill" && arg != "清心散" && arg != "散")) {
        write("你想服用什麼藥散？(use pill)\n");
        return 1;
    }

    int cur_turb = me->query("turbidity");
    if (cur_turb <= 0) {
        write("你神台清明，並無紅塵濁氣侵蝕，無需浪費珍貴藥散。\n");
        return 1;
    }

    cur_turb -= 20;
    if (cur_turb < 0) cur_turb = 0;
    me->set("turbidity", cur_turb);

    tell_object(me, HIG "你仰頭將一包清心散調水服下，一股清涼藥力直透靈台天門！\n" +
                        "眼前的市井浮躁濁翳頓時消散，濁氣降低至 " + sprintf("%d", cur_turb) + "/100。\n" NOR);
    destruct(this_object());
    return 1;
}
