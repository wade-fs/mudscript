// clone/npc/mine_rat.c - 黑石地穴鼠（初階怪，Lv2）
#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name(([ "en": "Mine Rat", "zh-TW": "黑石地穴鼠", "zh-CN": "黑石地穴鼠" ]));
    set_short(([ "en": "a sharp-toothed mine rat", "zh-TW": "一隻尖牙地穴鼠", "zh-CN": "一只尖牙地穴鼠" ]));
    set_long(([
        "en": "This is a dirty gray rat that lurks in the mine shafts, gnawing on wooden supports with razor-sharp teeth.\n",
        "zh-TW": "這是一隻長年盤踞在古礦道陰暗處的黑石灰鼠，毛皮油膩骯髒，一雙血紅的小眼骨碌亂轉，嘴裡露著兩顆鋒利的長門牙，正瘋狂啃噬著支撐坑道的枕木。\n",
        "zh-CN": "这是一只长年盘踞在古矿道阴暗处的黑石灰鼠，毛皮油腻肮脏，一双血红的小眼骨碌乱转，嘴里露著两颗锋利的长门牙，正疯狂啃噬著支撑坑道的枕木。\n"
    ]));
    set_id(({ "mine rat", "rat", "地穴鼠", "尖牙地穴鼠", "灰鼠", "老鼠" }));

    level    = 2;
    stat_str = 8;
    stat_dex = 14;
    stat_con = 8;
    stat_int = 2;
    recalc_stats();
    hp = max_hp;

    set_exp_reward(40);
    set_gold_reward(5);
    set_respawn(30);
    set_aggro_msg("地穴灰鼠發出一聲尖銳的吱吱怪叫，亮出泛黃的毒齒猛撲過來！\n");
}
