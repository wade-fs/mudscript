// d/sects/taiqing/outer_dormitory.c
// 太清門・外門弟子通鋪房（Tier 2 宗門底層起居空間）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清門・外門弟子通鋪房");
    set_long("與香火鼎盛、白石鋪地的星律正殿截然不同，這排灰瓦土牆廂房裡只擺著兩條長長的杉木大通鋪。\n"
             "十幾床洗得發白的薄青布棉被疊成整齊方塊，床腳擺著弟子們磨破鞋底的草鞋、木盆與換洗道袍。\n"
             "牆角一隻鐵火盆正散出微弱的炭火餘溫，幾雙濕透的布襪掛在繩子上烤得微捲。\n"
             "向東推門出去便是【太清外門青石廣場】。\n");

    set_exits(([
        "east": "/d/sects/taiqing/outer_court.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", WHT "粗麻青布被褥摸著微涼卻乾淨乾燥，杉木通鋪床沿冰硬硌手。" NOR);
    set_smell("default", YEL "皂角洗滌後的淡淡布味、烤襪子的焦燥炭氣與一絲老舊杉木清香交織在一起。" NOR);
    set_listen("default", WHT "窗外松風低鳴，偶爾傳來屋角幾名累壞的外門師弟均勻微弱的鼾聲。" NOR);

    mapping nap_rule = ([
        "targets": ({ "bed", "dormitory", "通鋪", "歇息", "" }),
        "sp_cost": 0,
        "sensory_msg": HIG "你和衣在冰涼硬實的杉木通鋪上合眼小憩半刻，緊繃了整日的肩背筋骨漸漸鬆弛下來。" NOR,
        "train_stat": ([ "con": 8 ]),
        "exp_gain": 6,
        "quest_verb": "nap",
        "quest_target": "dormitory"
    ]);
    add_action_rule("nap", nap_rule);
    add_action_rule("歇息", nap_rule);
}
