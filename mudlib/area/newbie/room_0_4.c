#include "/include/config.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("幽暗森林入口");
    set_long("陰森的森林入口，彷彿一隻巨獸張開的大嘴。\n");
    set_coordinate(0, 4, 0);
    add_exit("east", "/area/newbie/room_1_4.c");
    add_exit("south", "/area/newbie/room_0_3.c");
}
