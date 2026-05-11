#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("綠意草地");
    set_long("一片翠綠的草地，微風吹過，草浪起伏。\n");
    set_coordinate(0, 1, 0);
    add_exit("east", "/area/newbie/room_1_1.c");
    add_exit("south", "/area/newbie/room_0_0.c");
    add_exit("north", "/area/newbie/room_0_2.c");
}
