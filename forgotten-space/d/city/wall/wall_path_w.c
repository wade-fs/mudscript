// d/city/wall/wall_path_w.c
// 金石府城牆・西段巡城步道

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城牆步道・西段");
    set_long("西面巡城步道沿著青河活水護城河緩緩拱抱。\n"
             "西望是一望無際的桑竹藥圃與青河平原，水汽瀰漫，晨昏多見薄霧。\n"
             "向西可進入西城望江水樓扼守水閘，往北直連北城步道，\n"
             "向下 (down) 則可走下西水門關口。\n");

    set_exits(([
        "down":  "/d/city/gate/gate_west.c",
        "north": "/d/city/wall/wall_path_n.c",
        "south": "/d/city/wall/wall_path_s.c",
        "west":  "/d/city/wall/wall_tower_w.c",
    ]));

    set("is_outdoor", 1);
}
