// /d/routes/qinghe_shallow_bend.c
// 青河漕運水路 (seg_city_qinghe_water, 300里) 節點 2：九曲淺灘・蘆花航標 (對應卷二 Ch.59)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_qinghe_water");
    set_node_index(2);
    set_short("青河漕運水路・九曲淺灘");
    set_long("河道在此處連折九彎，兩岸雪白的蘆花隨風飄灑。河心插著數十根塗紅的\n"
             "竹製水位航標，標示出水下暗礁與沙洲的吃水深度。一旦上游定神道觀私自下放石閘\n"
             "截水，重載糧船極易在此擱淺。向東順流回【青河主航道】，往西即可靠岸抵達【青河縣・漕運碼頭】。\n");

    set_exits(([
        "east": "/d/routes/qinghe_barge_channel.c",
        "west": "/d/counties/qinghe/ferry_dock.c",
    ]));

    set_coordinate(-6, 9, 0);
}
