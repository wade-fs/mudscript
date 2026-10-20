// /d/routes/panmu_post_approach.c
// 東線第一段 (seg_blackstone_panmu, 190里) 節點 3：盤木前驛站・夜半鐵檻 (對應卷二 Ch.41)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_blackstone_panmu");
    set_node_index(3);
    set_short("盤木前驛站・夜半鐵檻");
    set_long("走出虎跳峽的逼仄山谷，眼前豁然開朗，濃郁的冷杉松脂香氣撲面而來。\n"
             "路旁設有一座由百年巨木壘成的山林前驛站，專供往來黑石鋪與盤木縣的重載騾車\n"
             "換馬歇腳。驛站外釘著數道黑鐵包角的攔馬檻（夜半鐵檻），泥地上留著深淺不一的\n"
             "重車轍印與夜間巡防獵犬的爪痕。向南重入【虎跳峽便道】，往北即可踏入【盤木縣南門】。\n");

    set_exits(([
        "south": "/d/routes/tiger_leap_gorge.c",
        "north": "/d/counties/panmu/south_gate.c",
    ]));

    set_coordinate(3, 4, 0);
}
