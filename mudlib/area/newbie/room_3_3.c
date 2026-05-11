#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("鐵匠鋪");
    set_long("叮叮噹噹的打鐵聲不絕於耳，火爐裡的炭火正旺。\n");
    set_coordinate(3, 3, 0);
    add_exit("west", "/area/newbie/room_2_3.c");
    add_exit("east", "/area/newbie/room_4_3.c");
    add_exit("south", "/area/newbie/room_3_2.c");
    add_exit("north", "/area/newbie/room_3_4.c");
}
