// /area/newbie/room_4_6.c
#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIC("魔法研究室"));
    set_long("這裡瀰漫著淡淡的奧法能量氣息。四周的書架上堆滿了厚重的魔法書籍。\n導師薩魯曼正靜靜地坐在桌後，研究著一份古老的捲軸。\n");
    set_no_combat(1);
    set_has_lab(1);
    set_coordinate(4, 6, 0);
    add_exit("south", "/area/newbie/room_4_5.c");
    add_exit("north", "/area/newbie/room_4_7.c");

    spawn_npc("/npc/mage_teacher.c");
}
