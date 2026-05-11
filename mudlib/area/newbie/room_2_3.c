#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("北大門");
    set_long("新手村的北大門，門後是一片連綿的群山。\n");
    set_coordinate(2, 3, 0);
    add_exit("west", "/area/newbie/room_1_3.c");
    add_exit("east", "/area/newbie/room_3_3.c");
    add_exit("south", "/area/newbie/room_2_2.c");
    add_exit("north", "/area/newbie/room_2_4.c");
}
