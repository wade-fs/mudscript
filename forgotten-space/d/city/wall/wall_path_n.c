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
}
