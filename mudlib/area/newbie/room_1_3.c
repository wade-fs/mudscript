#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("村民住所");
    set_long("這裡居住著一些樸實的村民，屋頂冒著裊裊炊煙。\n");
    set_coordinate(1, 3, 0);
    add_exit("west", "/area/newbie/room_0_3.c");
    add_exit("east", "/area/newbie/room_2_3.c");
    add_exit("south", "/area/newbie/room_1_2.c");
    add_exit("north", "/area/newbie/room_1_4.c");
}
