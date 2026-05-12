// npc/creature/cave_bat.c - 洞窟蝙蝠（洞穴，Lv1）
#include "/include/config.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("洞窟蝙蝠");
    set_short("一隻黑翼蝙蝠");
    set_long("這隻蝙蝠掛在陰暗角落，一被驚動就在空中亂竄，發出令人不舒服的尖嘯。\n");
    set_id(({"cave_bat", "蝙蝠", "洞窟蝙蝠"}));

    level    = 1;
    stat_str = 4;
    stat_dex = 16;
    stat_con = 5;
    recalc_stats();
    hp = max_hp;

    set_habitat(HABITAT_CAVE);
    set_behaviour(BEHAV_FLEE);
    set_flee_hp_pct(50);
    set_aggro_msg("蝙蝠被驚動，朝你猛衝！\n");

    set_exp_reward(25);
    set_gold_reward(3);
    set_respawn(30);
}
