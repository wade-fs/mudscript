#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("北部郊外");
    set_long("村子北邊的郊外，地勢逐漸升高。\n");
    set_coordinate(2, 4, 0);
    add_exit("west", "/area/newbie/room_1_4.c");
    add_exit("east", "/area/newbie/room_3_4.c");
    add_exit("south", "/area/newbie/room_2_3.c");
}
