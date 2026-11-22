// /d/sects/tiangong/gate.c
// 千機百巧門・天工閣・千鍛百巧門 (Ch.88)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・千鍛百巧門");
    set_long("兩扇刻滿繁複傘齒輪與應力榫卯紋路的厚重青銅大門，門楣上方數十道青石\n"
             "排煙通道終年噴吐著淡淡地肺白煙與煤灰氣息，山腹內隱隱傳來連綿不斷的鍛鐵轟鳴。\n"
             "向西下坡返回【雲津萬山廣場】，向東步入【千鍛地火廊暨千機院】。\n");

    set_exits(([
        "west": "/d/yunjin/wanshan_square.c",
        "east": "/d/sects/tiangong/thousand_mechanisms_hall.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "青銅大門上的傘齒輪浮雕稜角銳利冰冷，縫隙間沾著微溫的鍛造煙灰。" NOR);
    set_smell("default", YEL "山門上方排煙孔噴出的地肺白煙、焦煤硫磺與淡淡機油味撲鼻而來。" NOR);
    set_listen("default", HIY "門後山腹深處不斷傳出巨錘鍛鐵的「當——當——」轟鳴與水力風箱呼嘯聲。" NOR);

    mapping inspect_rule = ([
        "targets": ({ "gear", "gate", "齒輪", "青銅門", "" }),
        "sp_cost": 4,
        "sensory_msg": WHT "你俯身順著門扇上的傘齒輪應力榫卯紋路逐節摸索，隱約體會到力道傳導分流之妙。" NOR,
        "train_stat": ([ "int": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("inspect", inspect_rule);
    add_action_rule("觀榫卯", inspect_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
