// d/city/outer/south_road.c
// 金石府外・南嶺官道驛道 (連接黑石鋪與金石南關之核心動線)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南嶺官道・驛道漫塵");
    set_long("這是一條自八百里落龍古脈深山向北蜿蜒伸展的大平原官道。\n"
             "往南望去，黑石山脈蒼茫險峻的重巒疊嶂隱沒在濃重雲霧之中；\n"
             "向北眺望，平原極目處已能看見金石府城高逾三丈的深青色巍峨城牆與護城巨壕。\n"
             "道旁設有歇腳的破落涼亭，重型大車載著粗石巨木碾出兩道深深的車轍，煙塵滾滾。\n"
             "南下可返回深山礦村【黑石鋪】，北上則直達金石都城南方咽喉【金石南關】。\n");

    set_exits(([
        "southwest": "/d/village/square.c",
        "south":     "/d/village/square.c",
        "north":     "/d/city/gate/gate_south.c",
    ]));

    set("is_outdoor", 1);
}
