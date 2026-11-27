// d/sects/danding/sect_refectory.c
// 丹鼎門・清淡百味膳堂（Tier 2 宗門素膳與底層弟子交流之地）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎門・清淡百味膳堂");
    set_long("青瓦木樑下擺著兩長溜條木食桌與長凳，兩口黑沉沉的大鐵灶終年騰著滾燙米湯霧氣。\n"
             "火頭道姑用大木勺將熬得軟爛的陳皮蓮子糙米粥、素炒野菜與醃蘿蔔乾盛進粗陶大碗裡，\n"
             "無論是丹鼎外門雜役，還是偶爾偷偷摸來打牙祭的太清門窮苦師弟，都安靜蹲在門邊端碗喝得額角冒汗。\n"
             "向北邁過低矮木檻即是【百草靈圃】。\n");

    set_exits(([
        "north": "/d/sects/danding/herb_garden.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);
    set("has_tavern", 1);

    set_touch("default", YEL "燙手的粗陶大碗碗壁厚實糙手，條木長凳被無數雜役蹭得油光發亮。" NOR);
    set_smell("default", HIG "陳皮蓮子粥溫潤清甜的米香、麻油拌野菜味與老灶柴煙交融出安穩的家常食氣。" NOR);
    set_listen("default", WHT "長凳上滿屋子吸溜喝熱粥的輕響，以及鐵鍋蓋掀起時呼啦冒出的蒸氣聲。" NOR);

    mapping eat_rule = ([
        "targets": ({ "porridge", "meal", "粥", "熱粥", "" }),
        "sp_cost": 0,
        "sensory_msg": HIG "你捧起那隻燙得指腹發紅的粗陶大碗，將清香軟爛的陳皮蓮子糙米粥一飲而盡，整個人從胃袋一路暖到四肢。" NOR,
        "train_stat": ([ "con": 8 ]),
        "exp_gain": 8,
        "quest_verb": "eat",
        "quest_target": "refectory"
    ]);
    add_action_rule("eat", eat_rule);
    add_action_rule("用膳", eat_rule);

    spawn_npc("/clone/npc/folk/danding_cook_nun.c");
}
