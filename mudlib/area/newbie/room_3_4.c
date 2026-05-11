#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒野小徑");
    set_long("一條蜿蜒進入荒野的小路，泥土濕潤。\n");
    set_coordinate(3, 4, 0);
    add_exit("west", "/area/newbie/room_2_4.c");
    add_exit("east", "/area/newbie/room_4_4.c");
    add_exit("south", "/area/newbie/room_3_3.c");
}
