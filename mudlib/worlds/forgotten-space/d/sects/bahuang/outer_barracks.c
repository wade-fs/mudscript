// d/sects/bahuang/outer_barracks.c
// 八荒殿・巡山外營通鋪（Tier 2 北境戍邊武宗日常營帳）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒殿・巡山外營通鋪");
    set_long("一座依著黑山背風崖壁架起的厚牛皮雙層大軍帳，裡面排著八隻裝滿乾燥松針與獸皮的木架行軍床。\n"
             "帳柱上掛著擦滿防凍羊油的重劍、開刃破甲刀與備用羊毛護膝。\n"
             "帳外朔風如刀，裡頭鐵爐卻燒得通紅，幾名剛從長城巡哨歸來的外營武士正沉默地磨刀烤餅。\n"
             "向東北掀開厚牛皮門簾即是【黑山大營】。\n");

    set_exits(([
        "northeast": "/d/sects/bahuang/black_mountain_camp.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "粗硬冰冷的老羊皮帳褥與塗滿黏稠動物油脂的鍛鐵刀身透出北方軍伍獨有的粗糙力量感。" NOR);
    set_smell("default", YEL "羊脂擦刀油味、烤乾糧餅焦香、汗漬皮甲酸氣與炭火燥味渾然一體。" NOR);
    set_listen("default", WHT "北風猛撞牛皮帳篷發出低沉悶響，夾雜著磨刀石上「嚓、嚓」均勻而冷酷的刮擦聲。" NOR);

    mapping sharpen_rule = ([
        "targets": ({ "blade", "knife", "重刀", "磨刀", "" }),
        "sp_cost": 10,
        "sensory_msg": WHT "你捏著浸過羊油的粗青石磨石沿刀刃穩定推磨十數下，刃口重新泛出一道冷冽寒芒。" NOR,
        "train_stat": ([ "str": 10, "per": 8 ]),
        "exp_gain": 14,
        "quest_verb": "sharpen",
        "quest_target": "blade"
    ]);
    add_action_rule("sharpen", sharpen_rule);
    add_action_rule("磨刀", sharpen_rule);

    spawn_npc("/clone/npc/folk/route_traveler.c");
}
