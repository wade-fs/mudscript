#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("訓練場");
    set_long("村裡的年輕人常在這裡練習戰鬥技巧，空氣中瀰漫著汗水的味道。\n");
    set_coordinate(3, 1, 0);
    add_exit("west", "/area/newbie/room_2_1.c");
    add_exit("east", "/area/newbie/room_4_1.c");
    add_exit("south", "/area/newbie/room_3_0.c");
    add_exit("north", "/area/newbie/room_3_2.c");
}
