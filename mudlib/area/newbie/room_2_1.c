#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("南大門");
    set_long("新手村的南大門，門口有幾名守衛在巡邏。\n");
    set_coordinate(2, 1, 0);
    add_exit("west", "/area/newbie/room_1_1.c");
    add_exit("east", "/area/newbie/room_3_1.c");
    add_exit("south", "/area/newbie/room_2_0.c");
    add_exit("north", "/area/newbie/room_2_2.c");
}
