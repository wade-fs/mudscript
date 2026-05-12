#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("廣場北空地");
    set_long("廣場北方一塊開闊的空地，幾棵老樹枝幹橫斜。仰頭望去，空中盤旋著一隻碩大的猛禽，牠的影子在地面掠過——讓人不敢大意。\n");
    set_coordinate(2, 6, 0);
    add_exit("west",  "/area/newbie/room_1_6.c");
    add_exit("east",  "/area/newbie/room_3_6.c");
    add_exit("north", "/area/newbie/room_2_7.c");
    add_exit("south", "/area/newbie/room_2_5.c");

    object hawk = clone_object("/npc/creature/sky_hawk.c");
    if (hawk) move_object(hawk, this_object());
}
