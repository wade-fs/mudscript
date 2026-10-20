// d/city/east/wu_barracks.c
// 城防軍宿營

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("軍鎮・城防軍宿營");
    set_long("這是一間長達十餘丈的大通鋪營房。\n"
             "板床上整齊疊放著軍卒的粗布被褥與皮甲包袱，屋角架著幾罈烈酒。\n"
             "幾名輪休的老兵圍在火盆邊喝著粗茶，擦拭腰刀，笑談邊防瑣事。\n"
             "東面推開木門可回到八方武館正堂。\n");

    set_exits(([
        "east": "/d/city/east/wu_hall.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/wu_barracks_veteran.c");
}
