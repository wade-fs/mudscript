#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("南北大道");
    set_long("一條整潔的石板路，貫穿城鎮南北。\n");
    set_coordinate(4, 6, 0);
    add_exit("west", "/area/newbie/room_3_6.c");
    add_exit("east", "/area/newbie/room_5_6.c");
    add_exit("south", "/area/newbie/room_4_5.c");
    add_exit("north", "/area/newbie/room_4_7.c");
}
