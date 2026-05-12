#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("城鎮街道");
    set_long("這裡是一條安靜的街道，偶爾有居民走過。\n");
    set_coordinate(7, 3, 0);
    add_exit("west", "/area/newbie/room_6_3.c");
    add_exit("south", "/area/newbie/room_7_2.c");
    add_exit("north", "/area/newbie/room_7_4.c");
}
