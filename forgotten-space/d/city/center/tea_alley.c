// d/city/center/tea_alley.c
// 金石城中・槐蔭茶肆（Tier 1 城市市井生活支翼：茶水歇腳、市井閒話與代寫家書）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城中・槐蔭茶肆");
    set_long("穿過金石大客棧後巷月洞門，兩株枝葉繁茂的老槐樹遮出一方喧鬧卻難得愜意的露天井。\n"
             "十幾張油膩膩的榆木矮桌沿牆排開，茶博士老林拎著長嘴銅壺在桌縫間穿梭注水。\n"
             "跑腳的力夫、換班喝口粗茶的捕快，以及替不識字苦力代寫家書的落第秀才混坐一處。\n"
             "向南穿回月洞門即是【金石大客棧】大堂。\n");

    set_exits(([
        "south": "/d/city/center/inn_main.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set("has_tavern", 1);

    set_touch("default", YEL "被無數隻手肘磨得油亮發暗的榆木桌面，還留著上一位茶客灑出的溫熱茶漬。" NOR);
    set_smell("default", HIG "廉價茉莉花茶葉的清香壓過了市井汗味，夾雜著槐花微甜與墨條研磨的微苦。" NOR);
    set_listen("default", CYN "「嘩——」長嘴銅茶壺高沖低斟的水線聲裡，夾雜著書生吟詩、猜拳聲與銅板敲桌響。" NOR);

    mapping sip_rule = ([
        "targets": ({ "tea", "bowl", "粗茶", "茶水", "" }),
        "sp_cost": 0,
        "sensory_msg": HIG "你花十文錢端起一隻燙手的粗瓷大碗慢吞吞啜了一口，茉莉花茶雖苦中帶澀，卻瞬間潤開了乾渴的喉嚨，精神舒緩不少。" NOR,
        "train_stat": ([ "per": 8 ]),
        "exp_gain": 6,
        "quest_verb": "drink_tea",
        "quest_target": "tea_alley"
    ]);
    add_action_rule("tea", sip_rule);
    add_action_rule("喝茶", sip_rule);

    spawn_npc("/clone/npc/folk/tea_doctor_lin.c");
}
