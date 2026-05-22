#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(GRN("藥劑店"));
    set_long("這是一間溫馨的小木屋，屋子裡瀰漫著淡淡的草藥清香。\n艾拉正在這裡忙碌著，櫃檯上擺放著幾瓶顏色鮮豔的藥劑。\n");
    set_no_combat(1);
    set_coordinate(2, 2, 0);
    add_exit("east",  "/area/newbie/room_3_2.c");
    add_exit("west",  "/area/newbie/room_1_2.c");
    add_exit("north", "/area/newbie/room_2_3.c");
    add_exit("south", "/area/newbie/room_2_1.c");

    // 產生老闆
    spawn_npc("/npc/herbalist.c");
}
