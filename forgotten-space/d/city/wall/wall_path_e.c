// d/city/wall/wall_path_e.c
// 金石府城牆・東段巡城步道

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城牆步道・東段");
    set_long("巡城青石步道在此沿東側城牆筆直延展。\n"
             "牆外是百丈深的礬石峽谷險隘，牆內則可俯瞰軍鎮大校場的滾滾操演煙塵。\n"
             "向東可進入東城烽燧角樓，向南直連南牆步道，\n"
             "向下 (down) 順石梯可直落東關城門內側。\n");

    set_exits(([
        "down":  "/d/city/gate/gate_east.c",
        "north": "/d/city/wall/wall_path_n.c",
        "south": "/d/city/wall/wall_path_s.c",
        "east":  "/d/city/wall/wall_tower_e.c",
    ]));

    set("is_outdoor", 1);
}
