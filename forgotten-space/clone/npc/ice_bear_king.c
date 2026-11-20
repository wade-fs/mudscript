// /clone/npc/ice_bear_king.c
// 北荒冰熊王・荒古戰神遺塚阻關凶獸 (ice_bear_king) - 荒古戰神遺塚 (Ch.105)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("北荒冰熊王");
    set_short(HIW "二階高階凶獸・北荒冰熊王" NOR);
    set_long("身高近丈、渾身覆滿厚重冰晶毛皮的巨熊，一雙飢紅暴躁的血目順著氣味穿過爆破石隙\n"
             "堵死了返回斷崖繩索的退路，厚重熊掌拍向黑色巨柱時震得冰屑簌簌掉落；唯咽喉軟毛下方\n"
             "三寸乃受創要害，亦極為忌憚燃起的火把火光。\n");
    set_id(({ "ice_bear_king", "bear_king", "ice bear", "北荒冰熊王", "冰熊王" }));

    setup_archetype("D", 82);
    set("class", "beast");
    set("faction", "wastes_beast");
    set("home_room", "/d/wastes/war_god_tomb.c");

    set_exp_reward(1700);
    set_gold_reward(350);
    set_drop_list(({ "/item/material/wolf_fur.c" }));
    set_respawn(90);
    set_aggro_msg("北荒冰熊王發出震耳欲聾的咆哮堵住斷谷出口，雙掌撕風直拍玄石巨柱！\n");
    set_special_atk("碎冰熊掌重拍", 60);
}
