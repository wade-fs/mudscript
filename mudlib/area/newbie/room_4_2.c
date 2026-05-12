#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("南北大道");
    set_long("一條整潔的石板路，貫穿城鎮南北。\n");
    set_coordinate(4, 2, 0);
    add_exit("west", "/area/newbie/room_3_2.c");
    add_exit("east", "/area/newbie/room_5_2.c");
    add_exit("south", "/area/newbie/room_4_1.c");
    add_exit("north", "/area/newbie/room_4_3.c");
}
