// d/city/wall/wall_tower_w.c
// 西城望江水樓

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("西城・望江水樓");
    set_long("水樓扼守於西水門正上方，地底設有六副沉重的絞盤吊索，\n"
             "操控著重達萬斤的入河生鐵重柵。水軍哨官在此居高臨下俯瞰漕船往來，\n"
             "嚴防暗道水鬼與夜間偷渡夾帶違禁私鹽。向東推門回到西段巡城步道。\n");

    set_exits(([
        "east": "/d/city/wall/wall_path_w.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/wall_tower_w_navalofficer.c");
}
