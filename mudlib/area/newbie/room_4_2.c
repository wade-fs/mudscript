#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒原");
    set_long("一眼望不到頭的荒原，只有零星的幾棵枯樹。\n");
    set_coordinate(4, 2, 0);
    add_exit("west", "/area/newbie/room_3_2.c");
    add_exit("south", "/area/newbie/room_4_1.c");
    add_exit("north", "/area/newbie/room_4_3.c");
}
