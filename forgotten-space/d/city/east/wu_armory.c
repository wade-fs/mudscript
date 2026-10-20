// d/city/east/wu_armory.c
// 披甲兵器庫

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八方武館・披甲兵器庫");
    set_long("這座戒備森嚴的軍械重地內瀰漫著濃烈的防鏽桐油與磨刀石氣味。\n"
             "牆上整齊懸掛著數百副熟皮鐵甲、鎖子甲與來自鎮風縣的獸骨硬弓。\n"
             "司庫典軍正帶著磨刀匠在沙輪前火花四濺地打磨重型開山朴刀。\n"
             "向西穿過厚重生鐵門可回到八方武館正堂。\n");

    set_exits(([
        "west": "/d/city/east/wu_hall.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/wu_armory_quartermaster.c");
}
