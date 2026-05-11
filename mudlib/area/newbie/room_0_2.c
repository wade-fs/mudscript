#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("森林小溪");
    set_long("一條清澈的小溪流經這裡，叮咚的水聲悅耳動聽。\n");
    set_coordinate(0, 2, 0);
    add_exit("east", "/area/newbie/room_1_2.c");
    add_exit("south", "/area/newbie/room_0_1.c");
    add_exit("north", "/area/newbie/room_0_3.c");
}
