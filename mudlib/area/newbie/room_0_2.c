#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("城牆腳下");
    set_long("城鎮西側古老石牆的腳下，地面有多處隆起和裂縫，這裡的土壤被什麼東西從地底掀翻了。踩在鬆軟的泥土上，偶爾能感受到地面微微震動。\n");
    set_coordinate(0, 2, 0);
    add_exit("east",  "/area/newbie/room_1_2.c");
    add_exit("north", "/area/newbie/room_0_3.c");
    add_exit("south", "/area/newbie/room_0_1.c");

    object beast = clone_object("/npc/creature/mole_beast.c");
    if (beast) move_object(beast, this_object());
}
