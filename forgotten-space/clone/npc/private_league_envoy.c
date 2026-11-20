// /clone/npc/private_league_envoy.c
// 赤煉心腹大執事・冰谷截殺頭目 (private_league_envoy) - 冰谷窄口 (Ch.109-110)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("私盟大執事");
    set_short(HIR "千機堂副執印・私盟大執事" NOR);
    set_long("身披黑曜護心精甲的中年執事（二階八十八重），手中緊握一柄刻滿赤火金紋符文的長刀，\n"
             "腰間懸著天工閣千機堂副執印暗金令牌，與黑石鋪炸礦雷管同源批號配刀一應俱全。\n"
             "他在方舟東側母脈督導盜掘失敗後親率死士與虎煞戰鬥機關獸堵死冰谷窄口，誓奪樣本滅口！\n");
    set_id(({ "private_league_envoy", "envoy", "chief_envoy", "私盟大執事", "大執事" }));

    setup_archetype("E", 88);
    set("class", "gong");
    set("faction", "private_league");
    set("roles", ({ "boss", "enforcer" }));
    set("home_room", "/d/wastes/ice_valley_exit.c");

    set_exp_reward(2200);
    set_gold_reward(600);
    set_drop_list(({ "/clone/item/ev3_envoy_tally.c" }));
    set_respawn(120);
    set_aggro_msg("私盟大執事長刀直指雪道怒喝：「把鑽頭殘件、玉瓶樣本與黑冰斷谷那些破爛全都留下，一個活口也不放走！」\n");
    set_special_atk("赤火金紋長刀罡", 72);
}
