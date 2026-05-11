#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒廢農田");
    set_long("這片農田顯然已經很久沒人耕種了，長滿了雜草。\n");
    set_coordinate(4, 1, 0);
    add_exit("west", "/area/newbie/room_3_1.c");
    add_exit("south", "/area/newbie/room_4_0.c");
    add_exit("north", "/area/newbie/room_4_2.c");
}
