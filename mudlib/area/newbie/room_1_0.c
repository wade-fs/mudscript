#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("南部小徑");
    set_long("一條通往南方郊野的小徑，路邊開滿了不知名的小花。\n");
    set_coordinate(1, 0, 0);
    add_exit("west", "/area/newbie/room_0_0.c");
    add_exit("east", "/area/newbie/room_2_0.c");
    add_exit("north", "/area/newbie/room_1_1.c");
}
