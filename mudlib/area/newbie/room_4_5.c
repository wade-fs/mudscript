#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIW("冒險者公會"));
    set_long("這裡是新手村的公會大廳，天花板很高，四周掛著各種戰利品與地圖。\n幾名冒險者正坐在長椅上休息，氣氛顯得既嚴肅又熱鬧。\n");
    set_no_combat(1);
    set_coordinate(4, 5, 0);
    add_exit("east",  "/area/newbie/room_5_5.c");
    add_exit("west",  "/area/newbie/room_3_5.c");
    add_exit("north", "/area/newbie/room_4_6.c");
    add_exit("south", "/area/newbie/room_4_4.c"); // 連接中央廣場

    // 產生老闆
    spawn_npc("/npc/guild_master.c");
}
