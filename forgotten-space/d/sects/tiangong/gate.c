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
}
