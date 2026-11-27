// /d/routes/tianfeng_gorge_pass.c
// 北塞天風馳道 (seg_city_zhenfeng, 300里) 節點 2：天風谷咽喉・飛沙隘口 (對應卷二 Ch.61-62)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhenfeng");
    set_node_index(2);
    set_short("天風谷咽喉・飛沙隘口");
    set_long("兩側萬仞刀削般的玄黑絕壁將天空擠成一線，來自極北荒原的狂暴罡風在\n"
             "狹長谷道內呼嘯迴盪，刮得人面頰生疼。崖壁高處可見被風沙長年打磨出的半透明\n"
             "風蝕石英礦帶。玄冥冬歲暴雪時，重型大車在此寸步難行。向南回【北塞天風馳道】，\n"
             "往北穿出谷口即達【鎮風縣・南塞巨石甕城門】。\n");

    set_exits(([
        "south": "/d/routes/north_wind_highway.c",
        "north": "/d/counties/zhenfeng/south_gate.c",
    ]));

    set_coordinate(0, 15, 0);
}
