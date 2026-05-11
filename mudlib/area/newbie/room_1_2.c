#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("西大門");
    set_long("新手村的西大門，通往茂密的森林。\n");
    set_coordinate(1, 2, 0);
    add_exit("west", "/area/newbie/room_0_2.c");
    add_exit("east", "/area/newbie/room_2_2.c");
    add_exit("south", "/area/newbie/room_1_1.c");
    add_exit("north", "/area/newbie/room_1_3.c");
}
