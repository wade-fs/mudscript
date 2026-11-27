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

    set_touch("default", WHT "青石垛口被東面峽谷吹來的礦砂磨得粗礪刮手，地面巡道卻被守軍靴底踩得平實。" NOR);
    set_smell("default", YEL "牆外礬石峽谷飄來的微澀硫磺風塵味，與牆內軍鎮校場的汗味塵土。" NOR);
    set_listen("default", HIY "牆內大校場整齊的操練吼聲此起彼落，夾著東面峽谷峭壁反射回來的風嘯。" NOR);

    mapping lookout_rule = ([
        "targets": ({ "valley", "east", "瞭望", "校場", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你扶著東牆垛口朝外俯瞰百丈礬石峽谷，又回望校場煙塵，對金石東線防勢瞭然於胸。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("lookout", lookout_rule);
    add_action_rule("瞭望", lookout_rule);
}
