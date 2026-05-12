#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("廢棄廣場");
    set_long("這是城鎮東北角的一塊廢棄空地，地面凹凸不平，幾根斷裂的石柱東倒西歪。石柱上有古老符文的痕跡，空氣中有股說不出來的壓迫感。\n");
    set_coordinate(7, 6, 0);
    add_exit("north", "/area/newbie/room_7_7.c");
    add_exit("west",  "/area/newbie/room_6_6.c");
    add_exit("south", "/area/newbie/room_7_5.c");

    object golem = clone_object("/npc/creature/stone_golem.c");
    if (golem) move_object(golem, this_object());
}
