#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("東西大道");
    set_long("寬闊的街道兩旁開滿了各式小店。\n");
    set_coordinate(7, 4, 0);
    add_exit("west", "/area/newbie/room_6_4.c");
    add_exit("south", "/area/newbie/room_7_3.c");
    add_exit("north", "/area/newbie/room_7_5.c");
}
