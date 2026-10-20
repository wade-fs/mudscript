// d/city/north/gong_forge.c
// 千錘地爐坊 (鍛造大師莫錘、物道辨材考核)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・千錘地爐坊");
    set_long("這座巨大的高溫鍛造工坊熱浪滾滾，火星四濺。\n"
             "地底連通微弱地火餘脈，四座丈許高的巨型熔爐晝夜不熄。\n"
             "原料完全依託烈礬縣赤銅與重石縣重玄粗生鐵錠，地上堆滿了暗紅粗礦。\n"
             "鍛造大師莫錘手持重錘立在巨型鐵砧前，專試學徒摸骨辨材眼力 (ask mochui about 辨材)。\n"
             "南面通往萬機正堂，往東是官造石作場，往西則是戒備森嚴的硝火作。\n");

    set_exits(([
        "south": "/d/city/north/gong_hall.c",
        "east":  "/d/city/north/gong_stone.c",
        "west":  "/d/city/north/gong_fireworks.c",
    ]));

    set("is_outdoor", 0);
    set("has_forge", 1);
    spawn_npc("/clone/npc/gong_mochui.c");
}
