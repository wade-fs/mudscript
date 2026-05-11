#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("寧靜池塘");
    set_long("這是一個平靜的池塘，水面如鏡，倒映著天空的白雲。\n");
    set_coordinate(0, 0, 0);
    add_exit("east", "/area/newbie/room_1_0.c");
    add_exit("north", "/area/newbie/room_0_1.c");
}
