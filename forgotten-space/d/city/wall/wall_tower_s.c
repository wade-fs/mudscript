// d/city/wall/wall_tower_s.c
// 南城映翠箭樓

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南城・映翠箭樓");
    set_long("此箭樓高聳於南關西翼，俯瞰著整片向陽盆地與南部盤木林海。\n"
             "樓內設有機巧床弩維護台，幾名弓兵教頭正在擦拭以百鍊獸筋絞合的硬弓重弦。\n"
             "向東推開石門可回到南牆巡城步道。\n");

    set_exits(([
        "north": "/d/city/wall/wall_path_s.c",
    ]));

    set("is_outdoor", 0);
}
