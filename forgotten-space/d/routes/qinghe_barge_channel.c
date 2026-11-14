// /d/routes/qinghe_barge_channel.c
// 青河漕運水路 (seg_city_qinghe_water, 300里) 節點 1：青河主航道・平底駁船線 (對應卷二 Ch.58-59)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_qinghe_water");
    set_node_index(1);
    set_short("青河漕運水路・主航道");
    set_long("寬闊的青河主航道上，數十艘滿載洗靈草與秋糧的平底漕船正順流而下。\n"
             "兩岸蘆葦蒼茫，水關緝私快艇不時吹響號角，靠幫登船抽檢藥箱封條。此段為純水路\n"
             "航道，快馬無法通行。向東順流直抵【金石府城・西水門】，往西逆流而上通往【九曲淺灘】。\n");

    set_exits(([
        "northeast": "/d/city/gate/gate_west.c",
        "east":      "/d/city/gate/gate_west.c",
        "west":      "/d/routes/qinghe_shallow_bend.c",
    ]));

    set_coordinate(-4, 9, 0);
}
