#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("亂石崗");
    set_long("這裡到處都是散亂的岩石，走起路來需要格外小心。\n");
    set_coordinate(3, 0, 0);
    add_exit("west", "/area/newbie/room_2_0.c");
    add_exit("east", "/area/newbie/room_4_0.c");
    add_exit("north", "/area/newbie/room_3_1.c");
}
