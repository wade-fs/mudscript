#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("南部郊野");
    set_long("這裡是一片開闊的郊野，可以看到遠處起伏的山巒。\n");
    set_coordinate(2, 0, 0);
    add_exit("west", "/area/newbie/room_1_0.c");
    add_exit("east", "/area/newbie/room_3_0.c");
    add_exit("north", "/area/newbie/room_2_1.c");
}
