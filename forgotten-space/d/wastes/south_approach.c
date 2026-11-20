// /d/wastes/south_approach.c
// 北荒南沿入口（Ch.102 三宗聯合勘探隊出發整隊與正北偏東切入點）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・南沿入口");
    set_long("跨出長城關隘後進入北荒外荒裂谷的第一片開闊凍原，地上並列著上百名三宗內門精銳與\n"
             "二十四輛繡「泥」字灰布小旗的雪橇犬暨北地犛牛貨橇踏出的深轍；唯隊尾三輛覆蓋\n"
             "雙層厚黑布的赤煉重車轍印格外深沉，竟悄悄偏離長城陣基修補方位指向正北偏東深谷！\n"
             "向南退回【黑山長城北關雪道】，往北深入【雪原行腳營地】。\n");

    set_exits(([
        "south": "/d/wastes/black_mountain_pass.c",
        "north": "/d/wastes/snow_caravan_camp.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/qi_shiliu.c");
}
