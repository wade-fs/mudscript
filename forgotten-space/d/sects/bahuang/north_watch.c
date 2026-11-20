// /d/sects/bahuang/north_watch.c
// 八荒武山・北荒巡哨營 (Ch.94：測冰鐵簽與巡哨斥候駐點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・北荒巡哨營");
    set_long("緊貼長城西段雉堞搭建的哨所石屋，木架上整齊插著十餘根綁了紅布條的測冰長鐵簽、\n"
             "牛筋安全繩與單筒遠鏡。斥候祁無傷在此標繪北荒雪線與獸道異常，記下大裂谷深處\n"
             "每逢深夜便隱隱傳來的規律地底震聲。\n"
             "向東沿城牆走廊返回【北線長城巡防牆暨關口】。\n");

    set_exits(([
        "east": "/d/sects/bahuang/great_wall_gate.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/qi_wushang.c");
}
