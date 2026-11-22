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

    set_touch("default", YEL "向陽青石城磚被日頭曬得微溫乾燥，箭垛旁的硬木弩架打磨得圓滑堅實。" NOR);
    set_smell("default", GRN "南嶺吹來的草木暖風混著城內市井炊煙與南關官道的馬糞塵氣。" NOR);
    set_listen("default", HIY "城牆下南關市集與糧行的喧鬧人聲隨風飄上牆頭，夾著巡城兵卒整齊的甲葉摩擦聲。" NOR);

    mapping lookout_rule = ([
        "targets": ({ "south", "basin", "瞭望", "官道", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你憑垛南望，向陽盆地的田畝、官道蜿蜒車龍與落龍古脈盡收眼底。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("lookout", lookout_rule);
    add_action_rule("瞭望", lookout_rule);

    spawn_npc("/clone/npc/city_gate_guard.c");
}
