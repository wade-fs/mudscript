// d/city/wall/wall_tower_e.c
// 東城烽燧角樓

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("東城・烽燧角樓");
    set_long("這座依崖而建的四方石樓設有三座以烈礬縣耐火磚築成的常備狼煙烽燧。\n"
             "烽火長在此嚴密監視東麓大峽谷動向，一旦發現地煞暴湧或強梁犯境，\n"
             "瞬息之間狼煙便可引燃直衝雲霄。\n"
             "往西走下石階可回到東段巡城步道。\n");

    set_exits(([
        "west": "/d/city/wall/wall_path_e.c",
    ]));

    set("is_outdoor", 0);
}
