#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("獵人小屋");
    set_long("這是一座堅固的木屋，牆上掛著一些獸皮和陷阱。\n");
    set_coordinate(4, 4, 0);
    add_exit("west", "/area/newbie/room_3_4.c");
    add_exit("south", "/area/newbie/room_4_3.c");
}
