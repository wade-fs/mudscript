// /area/newbie/room_6_6.c
#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(GRN("翠綠草原"));
    set_long("這裡是一片廣闊的草原，微風拂過，草浪起伏。\n遠處可以看到幾匹野馬正在悠閒地吃草。\n");
    set_coordinate(6, 6, 0);
    add_exit("west", "/area/newbie/room_5_6.c");
    add_exit("south", "/area/newbie/room_6_5.c");

    spawn_npc("/npc/horse.c");
}
