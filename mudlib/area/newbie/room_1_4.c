#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("森林邊緣");
    set_long("樹木開始變得稀疏，光線也明亮了許多。\n");
    set_coordinate(1, 4, 0);
    add_exit("west", "/area/newbie/room_0_4.c");
    add_exit("east", "/area/newbie/room_2_4.c");
    add_exit("south", "/area/newbie/room_1_3.c");
}
