#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(CYAN("中央廣場"));
    set_long("這裡是新手村的正中央，寬闊的廣場由潔淨的石板鋪成。廣場中央矗立著一座巨大的噴泉，水花在陽光下閃爍著七彩的光芒。這裡也是許多冒險者出發與休憩的起點。\n");
    set_coordinate(4, 4, 0);
    add_exit("north", "/area/newbie/room_4_5.c");
    add_exit("south", "/area/newbie/room_4_3.c");
    add_exit("west", "/area/newbie/room_3_4.c");
    add_exit("east", "/area/newbie/room_5_4.c");
}
