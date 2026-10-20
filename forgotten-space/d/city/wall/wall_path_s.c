// d/city/wall/wall_path_s.c
// 金石府城牆・南段巡城步道

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城牆步道・南段");
    set_long("厚逾兩丈的青石巨磚城牆頂部寬闊平整，足可供三匹戰馬並行馳騁。\n"
             "南面女牆每隔數步便設有一處重弩箭垛，憑垛遠眺，整個向陽盆地與南部落龍古脈盡收眼底。\n"
             "巡城弓箭手正披甲按弓巡邏。向西可抵達南城映翠箭樓，向東沿步道轉向東牆，\n"
             "向下 (down) 則順石階步道直通金石南關城門。\n");

    set_exits(([
        "down":  "/d/city/gate/gate_south.c",
        "west":  "/d/city/wall/wall_path_w.c",
        "east":  "/d/city/wall/wall_path_e.c",
        "south": "/d/city/wall/wall_tower_s.c",
    ]));

    set("is_outdoor", 1);
}
