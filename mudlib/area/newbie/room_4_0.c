#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("古老遺蹟");
    set_long("一些殘破的石柱散落在這裡，訴說著往昔的輝煌。\n");
    set_coordinate(4, 0, 0);
    add_exit("west", "/area/newbie/room_3_0.c");
    add_exit("north", "/area/newbie/room_4_1.c");
}
