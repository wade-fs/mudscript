#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("雜貨店");
    set_long("這是村子裡的雜貨店，雖然簡陋，但日常用品還算齊全。\n");
    set_coordinate(1, 1, 0);
    add_exit("west", "/area/newbie/room_0_1.c");
    add_exit("east", "/area/newbie/room_2_1.c");
    add_exit("south", "/area/newbie/room_1_0.c");
    add_exit("north", "/area/newbie/room_1_2.c");
}
