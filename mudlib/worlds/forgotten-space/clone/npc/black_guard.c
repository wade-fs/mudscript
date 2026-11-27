// clone/npc/black_guard.c
// 城防軍黑甲弩衛 - 奉命搜殺屠村的精銳鐵衛 (小說第10、11章敵對精兵)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("黑甲弩衛");
    set_short(WHT "城防軍" NOR " 黑甲弩衛");
    set_long("一名身穿厚重黑鐵柳葉甲、頭戴生鐵盔的精銳軍卒。眼神森然麻木，\n"
             "手端一柄泛著幽綠劇毒光芒的精鋼三連發神臂弩，腰挎短刀，殺氣騰騰。\n"
             "正奉大統領之死令在暗巷巡查，凡見帶血刀兵者格殺勿論。\n");
    set_id(({ "black guard", "guard", "crossbowman", "黑甲弩衛", "弩衛", "黑甲衛" }));

    set_level(4);
    set_stat("str", 17);
    set_stat("dex", 16);
    set_stat("con", 18);
    recalc_stats();

    set("attitude", "aggressive");
    set("combat_exp", 1200);

    // 攜帶破甲箭
    object arrow = new("/clone/weapon/armor_piercing_arrow.c");
    if (arrow) arrow->move(this_object());
}

void die() {
    object me = query_temp("last_damage_from");
    if (me && userp(me)) {
        tell_object(me, WHT "黑甲弩衛重重栽倒在泥沼中，身上的柳葉鐵甲發出沉悶爆響！\n" NOR);
    }
    ::die();
}
