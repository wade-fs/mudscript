#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("低窪水塘旁");
    set_long("平民區一角有個低窪的小水塘，雨水長期積存讓這裡泥濘不堪。水塘邊的蘆葦叢中不時傳出嘶嘶聲——那裡不太安全。\n");
    set_coordinate(1, 1, 0);
    add_exit("east",  "/area/newbie/room_2_1.c");
    add_exit("west",  "/area/newbie/room_0_1.c");
    add_exit("north", "/area/newbie/room_1_2.c");
    add_exit("south", "/area/newbie/room_1_0.c");

    object snake = clone_object("/npc/creature/water_snake.c");
    if (snake) move_object(snake, this_object());

    object crab = clone_object("/npc/creature/mud_crab.c");
    if (crab) move_object(crab, this_object());
}
