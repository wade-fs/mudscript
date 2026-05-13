#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIG("煉金藥劑店"));
    set_long("店內瀰漫著一股濃郁的草藥味與化學試劑的味道。架子上擺滿了五顏六色的試劑瓶。這裡販賣著能夠治療傷口與恢復法力的神奇藥水。\n");
    set_no_combat(1);
    set_coordinate(4, 3, 0);
    add_exit("north", "/area/newbie/room_4_4.c");
    add_exit("south", "/area/newbie/room_4_2.c");
    
    object ob = clone_object("/npc/herbalist.c");
    if (ob) move_object(ob, this_object());
}
