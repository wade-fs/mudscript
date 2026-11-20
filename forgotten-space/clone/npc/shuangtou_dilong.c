// /clone/npc/shuangtou_dilong.c
// 雙頭霜甲地龍・永凍血原二階頂峰凶獸 (shuangtou_dilong) - 永凍血原 (Ch.103)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("雙頭霜甲地龍");
    set_short(HIB "二階頂峰凶獸・雙頭霜甲地龍" NOR);
    set_long("盤踞永凍血原、體長逾四丈的太古異變凶獸，周身披滿暗藍色厚重冰鱗。\n"
             "右邊頭顱鼓動硫磺毒囊吐出腐蝕暗紅毒漿（唯右顎下方充血時顯露不足兩指寬的逆鱗死穴），\n"
             "左邊頭顱則張吻噴出零下百度急凍白霧，巨尾橫掃足可震碎萬斤凍岩！\n");
    set_id(({ "shuangtou_dilong", "frost_dragon", "dilong", "雙頭霜甲地龍", "霜甲地龍", "地龍" }));

    setup_archetype("K", 82);
    set("class", "beast");
    set("faction", "wastes_beast");
    set("home_room", "/d/wastes/frozen_blood_plain.c");

    set_exp_reward(1800);
    set_gold_reward(420);
    set_drop_list(({ "/clone/item/pill_herb_poultice.c" }));
    set_respawn(90);
    set_aggro_msg("雙頭霜甲地龍猛地撞破兩尺厚凍冰掀翻雪橇車隊，左噴白霧冰煞、右蓄硫磺毒漿狂衝而來！\n");
    set_special_atk("雙首冰煞毒漿交吐", 65);
}
