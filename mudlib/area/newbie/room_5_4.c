#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIB("凱文的防具店"));
    set_long("店內陳列著各種皮甲與鎖子甲，散發著皮革與金屬的味道。牆上掛著幾面裝飾華麗的盾牌。\n");
    set_no_combat(1);
    set_coordinate(5, 4, 0);
    add_exit("west", "/area/newbie/room_4_4.c");
    add_exit("east", "/area/newbie/room_6_4.c");
}
