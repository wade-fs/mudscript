// /clone/npc/tiger_mech_beast.c
// 虎煞戰鬥機關獸・天工閣二階重甲傀儡 (tiger_mech_beast) - 冰谷窄口 (Ch.110)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("虎煞戰鬥機關獸");
    set_short(HIY "二階重甲傀儡・虎煞戰鬥機關獸" NOR);
    set_long("高約八尺、通體披掛精鐵重甲的重型機關猛虎，一對赤紅寶石眼眸閃著高壓靈力光芒，\n"
             "正面甲肋足以硬抗尋常二階法術；然其左前腿第三轉軸與膝部液壓閥門皆為應力脆弱死角，\n"
             "若遭腐金酸煙侵蝕後以鍛錘狠敲閥門便會瞬間癱瘓。\n");
    set_id(({ "tiger_mech_beast", "mech_beast", "tiger_mech", "虎煞戰鬥機關獸", "虎煞機關獸" }));

    setup_archetype("E", 84);
    set("class", "gong");
    set("faction", "private_league");
    set("home_room", "/d/wastes/ice_valley_exit.c");

    set_exp_reward(1600);
    set_gold_reward(300);
    set_respawn(120);
    set_aggro_msg("虎煞戰鬥機關獸低伏精鋼利爪，齒輪發出刺耳尖鳴猛撲上來！\n");
    set_special_atk("精鐵虎爪裂甲撲擊", 62);
}
