// d/city/north/gong_hall.c
// 百工總會・萬機正堂 (物道考核與受牒、歐陽大師)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工總會・萬機堂");
    set_long("整座大殿的樑柱結構皆以精密無比的榫卯咬合，不費一釘一鉚，令人歎為觀止。\n"
             "四面牆壁懸掛著各類天工機關總圖、水力大磨與城防絞盤拓本。\n"
             "百工總會匠首歐陽大師端坐於長條格物案前，案頭擺放著天工烏木尺與墨斗。\n"
             "凡完成辨材與敲榫考核的學徒，可在此向大師請頒匠籍 (ask ouyang about 匠籍)。\n"
             "往東可步出萬機堂回到外門坊口，向北通往千錘地爐坊，向南則是天工木作大棚。\n");

    set_exits(([
        "east":  "/d/city/north/gong_gate.c",
        "north": "/d/city/north/gong_forge.c",
        "south": "/d/city/north/gong_wood.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/gong_ouyang.c");
}
