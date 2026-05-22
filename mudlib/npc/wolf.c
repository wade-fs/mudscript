// npc/wolf.c - 野狼（中階怪）
#include "/include/config.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("野狼");
    set_short("一匹兇猛的野狼");
    set_long("這是一匹毛色灰黑、眼神兇狠的野狼，嘴邊還掛著幾縷白沫。\n");
    set_id(({"wolf","野狼","狼"}));

    level    = 3;
    stat_str = 10;
    stat_dex = 12;
    stat_con = 9;
    recalc_stats();
    hp = max_hp;

    set_exp_reward(90);
    set_gold_reward(15);
    set_drop_list(({"/item/weapon/short_sword.c"}));
    set_harvest_data(([
        "file": "/item/material/wolf_fur.c",
        "chance": 80
    ]));
    set_respawn(60);
    set_aggro_msg("野狼嗥叫一聲，露出鋒利的牙齒！\n");
}
