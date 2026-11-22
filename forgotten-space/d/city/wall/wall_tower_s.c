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

    set_touch("default", YEL "映翠箭樓內硬木弓架被掌心汗油養得溫潤光亮，箭羽羽毛柔順乾燥。" NOR);
    set_smell("default", GRN "南嶺吹來的清新松木風與塗在強弓牛筋弦上的蜂蠟清香。" NOR);
    set_listen("default", CYN "箭樓外樹梢風聲沙沙作響，偶爾聽見弓箭教頭試拉重弓發出的沉悶弦鳴。" NOR);

    spawn_npc("/clone/npc/wall_tower_s_archerymaster.c");
}
