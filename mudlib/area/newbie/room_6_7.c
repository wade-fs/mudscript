#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("後花園");
    set_long("城鎮邊緣安靜的角落，種滿了奇異的花草。\n");
    set_coordinate(6, 7, 0);
    add_exit("west", "/area/newbie/room_5_7.c");
    add_exit("east", "/area/newbie/room_7_7.c");
    add_exit("south", "/area/newbie/room_6_6.c");
}
