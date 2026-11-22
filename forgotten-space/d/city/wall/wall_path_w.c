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

    set_touch("default", CYN "西牆青磚上凝著護城河水汽帶來的微潮露水，摸上去涼潤微滑。" NOR);
    set_smell("default", HIG "西面桑竹藥圃吹來的清苦草葉香、濕潤河泥味與淡淡晨昏薄霧氣息。" NOR);
    set_listen("default", CYN "護城河活水嘩啦流淌，夾著城外水門碼頭船工撐篙的遙遠號子聲。" NOR);

    mapping lookout_rule = ([
        "targets": ({ "west", "river", "瞭望", "青河", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你倚著西牆垛口望向青河平原，漕運白帆與片片桑竹藥田如畫卷般在霧中展開。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("lookout", lookout_rule);
    add_action_rule("瞭望", lookout_rule);
}
