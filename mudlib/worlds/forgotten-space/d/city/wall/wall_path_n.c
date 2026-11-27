// d/city/wall/wall_path_n.c
// 金石府城牆・北段巡城步道

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城牆步道・北段");
    set_long("此處高踞於北關城門頂端，萬丈罡風自極北天風谷呼嘯而來，吹得軍旗獵獵作響。\n"
             "垛口前架設著數具機巧床弩，黑亮的純鋼弩箭指著遙遠的北山荒原。\n"
             "向北可進入巍峨的北城望荒箭樓，向西沿步道轉向西水門水樓，\n"
             "向下 (down) 則可走下北關城門。\n");

    set_exits(([
        "down":  "/d/city/gate/gate_north.c",
        "west":  "/d/city/wall/wall_path_w.c",
        "east":  "/d/city/wall/wall_path_e.c",
        "north": "/d/city/wall/wall_tower_n.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "北牆垛口與床弩絞盤鐵件冷得刺骨，表面覆著從天風谷吹來的細白沙塵。" NOR);
    set_smell("default", CYN "乾燥刺鼻的北方沙塵、冷鐵擦槍油味與獵獵吹拂的高空朔風氣息。" NOR);
    set_listen("default", WHT "萬丈北風扯動軍旗發出「噼啪」巨響，腳下北關門洞傳來沉重的馬車盤查聲。" NOR);

    mapping lookout_rule = ([
        "targets": ({ "north", "wastes", "瞭望", "北荒", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你頂著撲面朔風手搭涼棚北眺，天風谷與遙遠黑山長城的輪廓在灰白天際線上隱約可見。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("lookout", lookout_rule);
    add_action_rule("瞭望", lookout_rule);

    spawn_npc("/clone/npc/city_gate_guard.c");
}
