#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("城鎮街道");
    set_long("這裡是一條安靜的街道，偶爾有居民走過。\n");
    set_coordinate(5, 0, 0);
    add_exit("west", "/area/newbie/room_4_0.c");
    add_exit("east", "/area/newbie/room_6_0.c");
    add_exit("north", "/area/newbie/room_5_1.c");
}
