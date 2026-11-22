// d/sects/danding/outer_herb_terrace.c
// 丹鼎門・外門洗藥晾曬坡（Tier 2 宗門底層藥農與雜役日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("丹鼎門・外門洗藥晾曬坡");
    set_long("順著山腰泉水引出幾道竹槽石池，整片向陽石坡鋪滿了圓竹匾，曬著剛採挖下來的黃精、地骨皮與蛇床草。\n"
             "幾名僱來的山下藥農與丹鼎門雜役正捲起褲管蹲在冰冷山泉水池邊，刷洗帶泥藥根。\n"
             "誰都知道內門煉丹需要萬年靈芝與血精藥引，可撐起丹鼎門九成粗藥供應的，正是這些沾滿黃泥巴的竹匾。\n"
             "向西折回即達【百草靈圃】。\n");

    set_exits(([
        "west": "/d/sects/danding/herb_garden.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", CYN "引流而來的山泉水冰涼刺骨，指尖抓著草藥根莖上的濕黃泥與麻布篩網有些刮手。" NOR);
    set_smell("default", HIG "濃烈辛澀的泥土氣、新鮮切片黃精甜味與太陽曬暖後的乾燥藥草香混成一片。" NOR);
    set_listen("default", CYN "竹槽引水叮咚灌入石池，竹刷來回刷洗老藥根發出沙沙水響。" NOR);

    mapping wash_rule = ([
        "targets": ({ "herb", "root", "藥根", "草藥", "" }),
        "sp_cost": 8,
        "sensory_msg": HIG "你蹲在冰泉邊握緊硬棕刷，將幾筐帶泥生藥細心洗淨擺進竹匾攤開晾曬，指頭凍得發紅卻格外踏實。" NOR,
        "train_stat": ([ "per": 10, "dex": 6 ]),
        "exp_gain": 12,
        "quest_verb": "wash_herb",
        "quest_target": "herb"
    ]);
    add_action_rule("wash_herb", wash_rule);
    add_action_rule("洗藥", wash_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
