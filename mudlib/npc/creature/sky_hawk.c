// npc/creature/sky_hawk.c - 天空獵鷹（天空怪，Lv3）
#include "/include/config.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("天空獵鷹");
    set_short("一隻翱翔天際的獵鷹");
    set_long("這隻巨大的獵鷹翼展超過三公尺，以迅雷不及掩耳的速度俯衝攻擊地面上的獵物。\n");
    set_id(({"sky_hawk", "天空獵鷹", "獵鷹", "老鷹"}));

    level    = 3;
    stat_str = 11;
    stat_dex = 18;
    stat_con = 9;
    recalc_stats();
    hp = max_hp;

    set_habitat(HABITAT_SKY);
    set_behaviour(BEHAV_AGGRESSIVE);
    set_aggro_range(2);
    set_aggro_msg("天空獵鷹收翅俯衝，銳利的爪子朝你撲來！\n");
    set_special_atk("俯衝突擊", 30);

    set_exp_reward(85);
    set_gold_reward(15);
    set_drop_list(({"/item/consumable/health_potion.c"}));
    set_respawn(60);
}
