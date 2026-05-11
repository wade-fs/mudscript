#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("茂密叢林");
    set_long("陽光被茂密的樹葉遮擋，光線顯得有些昏暗。\n");
    set_coordinate(0, 3, 0);
    add_exit("east", "/area/newbie/room_1_3.c");
    add_exit("south", "/area/newbie/room_0_2.c");
    add_exit("north", "/area/newbie/room_0_4.c");
}
