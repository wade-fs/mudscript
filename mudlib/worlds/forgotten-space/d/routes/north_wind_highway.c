// /d/routes/north_wind_highway.c
// 北塞天風馳道 (seg_city_zhenfeng, 300里) 節點 1：拒馬石障 (對應卷二 Ch.61)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhenfeng");
    set_node_index(1);
    set_short("北塞天風馳道・拒馬石障");
    set_long("出了金石北關大車馬店，地勢一路向北緩緩抬升，草木漸稀，凜冽的北塞\n"
             "寒風捲著細沙撲面而來。馳道兩側每隔五里便築有一座防風石牆與鐵刺拒馬，供換防\n"
             "邊軍與押運皮甲的商隊避風整隊。向南可退回【外城近郊・大車馬店】，往北迎風前行\n"
             "即入【天風谷咽喉・飛沙隘口】。\n");

    set_exits(([
        "south": "/d/city/outer/post_depot.c",
        "north": "/d/routes/tianfeng_gorge_pass.c",
    ]));

    set_coordinate(0, 14, 0);
}
