// /d/routes/stone_highway_pavilion.c
// 西線第二段 (seg_city_zhongshi, 240里) 節點 1：西南條石馳道・車轍接官亭

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhongshi");
    set_node_index(1);
    set_short("西南條石馳道・車轍接官亭");
    set_long("這是一條由雙層重玄青石板嚴密鋪就的帝國官防馳道。路面被常年運送萬斤\n"
             "城防條石與粗生鐵錠的八輪鐵軸大車壓出兩道半尺深的石槽。馳道旁立著一座全石\n"
             "結構的接官涼亭，幾名押運條石的力士正靠在石柱旁灌著涼水。往西南直通石材與\n"
             "生鐵重鎮【重石縣北門】，向東北則匯入【金石府城南嶺官道匯流口】。\n");

    set_exits(([
        "southwest": "/d/counties/zhongshi/north_gate.c",
        "northeast": "/d/city/outer/south_road.c",
    ]));

    set_coordinate(-2, 9, 0);
}
