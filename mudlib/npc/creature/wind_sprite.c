// npc/creature/wind_sprite.c - 風之精靈（天空，Lv2，被動）
#include "/include/config.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("風之精靈");
    set_short("一隻飄逸的風之精靈");
    set_long("這隻精靈半透明的身軀隨風搖曳，能聽見它發出輕柔的哼鳴聲，彷彿在訴說著天空的故事。\n");
    set_id(({"wind_sprite", "風之精靈", "精靈", "風精靈"}));

    level    = 2;
    stat_str = 5;
    stat_dex = 20;
    stat_int = 14;
    stat_con = 5;
    recalc_stats();
    hp = max_hp;

    set_habitat(HABITAT_SKY);
    set_behaviour(BEHAV_PASSIVE);

    set_exp_reward(40);
    set_gold_reward(5);
    set_respawn(120);

    set_chat_topic("天空", "天空廣闊無垠，自由才是最美麗的事物。");
    set_chat_topic("風", "風無所不在，它帶著各地的消息飄來飄去。");
    set_chat_topic("飛行", "若你想飛翔，就必須先學會相信自己！");
}
