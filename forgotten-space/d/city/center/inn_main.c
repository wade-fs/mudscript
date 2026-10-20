// d/city/center/inn_main.c
// 金石大客棧 (三層雕樑石樓)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・金石大客棧");
    set_long("這座三層雕樑畫棟的青石大客棧是府城規格最高、聲名最盛的落腳之處。\n"
             "一樓大堂寬敞明亮，四面擺滿了酸枝木八仙桌，往來巨賈、世家子弟與各派修士杯盤狼藉。\n"
             "大掌櫃錢不換笑口常開地穿梭招呼，眼線遍佈全城市井。\n"
             "向南邁出大門可直達中央青石廣場，往東可步入官辦遞鋪驛館。\n");

    set_exits(([
        "south": "/d/city/center/square.c",
        "out":   "/d/city/center/square.c",
        "east":  "/d/city/center/post_station.c",
        "west":  "/d/city/center/granary.c",
    ]));

    set("is_outdoor", 0);
    set("has_tavern", 1);

    spawn_npc("/clone/npc/inn_main_qianbuhuan.c");
}
