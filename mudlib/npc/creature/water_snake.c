// npc/creature/water_snake.c - 水蛇（水中怪，Lv2）
#include "/include/config.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("水蛇");
    set_short("一條滑溜溜的水蛇");
    set_long("這是一條盤繞在水邊的灰綠色水蛇，鱗片在陽光下閃著冷光，吐著分叉的舌頭。\n");
    set_id(({"water_snake", "水蛇", "蛇"}));

    level    = 2;
    stat_str = 7;
    stat_dex = 14;
    stat_con = 7;
    recalc_stats();
    hp = max_hp;

    set_habitat(HABITAT_WATER);
    set_behaviour(BEHAV_AGGRESSIVE);
    set_aggro_range(1);
    set_aggro_msg("水蛇嘶嘶作聲，從水中竄出！\n");
    set_special_atk("毒牙咬噬", 20);

    set_exp_reward(55);
    set_gold_reward(8);
    set_drop_list(({"/item/consumable/health_potion.c"}));
    set_harvest_data(([
        "file": "/item/material/snake_venom.c",
        "chance": 70
    ]));
    set_respawn(45);
}
