#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("後花園");
    set_long("城鎮邊緣安靜的角落，種滿了奇異的花草。靠近牆角的石縫間偶爾有蝙蝠的翅膀聲，花叢中傳來低沉的喘息聲，這裡並不像表面看起來那麼平靜。\n");
    set_coordinate(7, 7, 0);
    add_exit("west",  "/area/newbie/room_6_7.c");
    add_exit("south", "/area/newbie/room_7_6.c");

    object bat = clone_object("/npc/creature/cave_bat.c");
    if (bat) move_object(bat, this_object());
}
