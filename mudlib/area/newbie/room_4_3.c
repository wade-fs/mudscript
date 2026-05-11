#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒野");
    set_long("這裡人跡罕至，充滿了未知的危險。\n");
    set_coordinate(4, 3, 0);
    add_exit("west", "/area/newbie/room_3_3.c");
    add_exit("south", "/area/newbie/room_4_2.c");
    add_exit("north", "/area/newbie/room_4_4.c");
}
