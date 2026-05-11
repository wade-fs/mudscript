#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("東大門");
    set_long("新手村的東大門，通往廣闊的荒原。\n");
    set_coordinate(3, 2, 0);
    add_exit("west", "/area/newbie/room_2_2.c");
    add_exit("east", "/area/newbie/room_4_2.c");
    add_exit("south", "/area/newbie/room_3_1.c");
    add_exit("north", "/area/newbie/room_3_3.c");
}
