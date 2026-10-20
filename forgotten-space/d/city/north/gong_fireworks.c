// d/city/north/gong_fireworks.c
// 硝火作 (官禁火器雷管要地)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・硝火作");
    set_long("這是一間深挖入地下的厚石防爆工坊，四壁貼滿了厚厚黃泥與生鐵夾板。\n"
             "空氣中瀰漫著刺鼻的高純度硫磺與烈礬硝石氣味，地上鋪滿細砂以防碰撞火花。\n"
             "火藥督造官嚴厲注視著每一道封裝工序，專門配製開山雷管與守城火毬。\n"
             "向東推開沉重鐵門可回到千錘地爐坊。\n");

    set_exits(([
        "east": "/d/city/north/gong_forge.c",
    ]));

    set("is_outdoor", 0);
}
