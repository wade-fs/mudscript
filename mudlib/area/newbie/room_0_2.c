#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("平民區");
    set_long("這裡是一排排整齊的石造民居。\n");
    set_coordinate(0, 2, 0);
    add_exit("east", "/area/newbie/room_1_2.c");
    add_exit("south", "/area/newbie/room_0_1.c");
    add_exit("north", "/area/newbie/room_0_3.c");
}
