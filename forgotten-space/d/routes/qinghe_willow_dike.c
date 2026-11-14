// /d/routes/qinghe_willow_dike.c
// 青河沿河官道 (seg_city_qinghe_land, 280里) 節點 1：青河柳堤官道 (對應卷二 Ch.58)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_qinghe_land");
    set_node_index(1);
    set_short("青河沿河官道・柳堤官道");
    set_long("順著青河主幹北岸修築的寬闊官道，兩側栽滿了垂柳與護堤桑樹。河面上\n"
             "白帆點點，滿載稻穀與藥材的平底駁船與岸上的車馬並肩而行。秋雨過後，低窪處\n"
             "積著淺水與車轍爛泥。向東可返回【城西近郊・青禾田】，往西續行則抵達【青河半途水驛】。\n");

    set_exits(([
        "northeast": "/d/city/outer/farmland_w.c",
        "east":      "/d/city/outer/farmland_w.c",
        "west":      "/d/routes/qinghe_post.c",
    ]));

    set_coordinate(-4, 10, 0);
}
