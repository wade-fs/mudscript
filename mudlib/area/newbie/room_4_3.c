#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(MAG("醉夢酒館"));
    set_long("酒館內人聲鼎沸，充滿了廉價麥酒的味道。幾張粗糙的木桌旁坐滿了吹牛的冒險者。\n老闆巴克正忙著擦拭吧台上的杯子。\n");
    set_no_combat(1);
    set_coordinate(4, 3, 0);
    add_exit("north", "/area/newbie/room_4_4.c");
    add_exit("south", "/area/newbie/room_4_2.c");
    
    // 產生老闆
    spawn_npc("/npc/bartender.c");
}
