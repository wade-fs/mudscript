// d/city/north/gong_alchemy.c
// 採百草分堂 (孫先生)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・採百草分堂");
    set_long("這座安靜清雅的分堂內架設著數具精銅蒸餾冷凝器具。\n"
             "藥坊管事孫先生正帶領藥工萃取來自青河的洗靈草精華與濁水縣特殊毒囊，\n"
             "專司配製官防金創止血藥散與百工淬火專用藥液。\n"
             "往東可步出藥堂回到天工木作大棚。\n");

    set_exits(([
        "east": "/d/city/north/gong_wood.c",
    ]));

    set("is_outdoor", 0);
    set("has_lab", 1);

    spawn_npc("/clone/npc/gong_alchemy_sunxiansheng.c");
}
