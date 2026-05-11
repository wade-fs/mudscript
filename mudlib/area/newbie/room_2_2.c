#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("新手村中央廣場");
    set_long("這裡是村子的中心，人來人往，非常熱鬧。廣場中央有一個噴泉。\n");
    set_coordinate(2, 2, 0);
    add_exit("west", "/area/newbie/room_1_2.c");
    add_exit("east", "/area/newbie/room_3_2.c");
    add_exit("south", "/area/newbie/room_2_1.c");
    add_exit("north", "/area/newbie/room_2_3.c");
}
