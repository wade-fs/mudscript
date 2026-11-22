// d/sects/taiqing/scripture_copy_hall.c
// 太清門・戒律抄經堂（Tier 2 宗門底層弟子單調苦差日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清門・戒律抄經堂");
    set_long("一間排著四十張黑漆木書案的狹長偏殿，窗戶開得高而窄，只透進冷白孤寂的山光。\n"
             "案上擺滿成疊粗黃竹紙、劣質松煙墨條與磨得發禿的狼毫筆。幾名年輕外門弟子正弓著背默默抄寫科儀，\n"
             "稍有走神或漏字，案前守著的戒律師兄便敲響木質戒尺。\n"
             "向西跨出偏門即是【太清外門青石廣場】。\n");

    set_exits(([
        "west": "/d/sects/taiqing/outer_court.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", CYN "黑漆木書案被手腕長年累月磨出兩道凹陷亮痕，握筆的中指關節隱隱發涼發酸。" NOR);
    set_smell("default", WHT "刺鼻的廉價松煙墨水味、微潮舊竹紙味與冷殿寒氣緊緊纏繞在一起。" NOR);
    set_listen("default", CYN "「沙沙……沙沙……」整齊又單調的毛筆劃過竹紙聲，偶爾被清脆一聲戒尺敲桌打斷。" NOR);

    mapping copy_rule = ([
        "targets": ({ "scripture", "book", "經卷", "科儀", "" }),
        "sp_cost": 10,
        "sensory_msg": CYN "你屏息凝神研好松煙墨，一筆一劃地在粗竹紙上謄完一卷《太清守靜科儀》，手腕酸麻卻也靜下了浮躁心氣。" NOR,
        "train_stat": ([ "int": 10, "per": 8 ]),
        "exp_gain": 15,
        "quest_verb": "copy",
        "quest_target": "scripture"
    ]);
    add_action_rule("copy", copy_rule);
    add_action_rule("抄經", copy_rule);

    spawn_npc("/clone/npc/folk/taiqing_copy_senior.c");
}
