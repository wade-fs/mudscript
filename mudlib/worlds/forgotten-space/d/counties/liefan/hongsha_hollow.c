// /d/counties/liefan/hongsha_hollow.c
// 烈礬縣 (Liefan County) 房間 9/14：紅砂坳・洗礬篩砂聚落 (轄下新手村 1)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("紅砂坳・洗礬篩砂聚落");
    set_long("這座坐落於赤紅山坳中的礦工村落，家家戶戶門前都砌著結晶池與篩洗槽。\n"
             "村民將採出的紅砂礬石粉碎後引山泉浸泡，析出雪白的明礬與暗紅的伴生硃砂晶。\n"
             "向北可返【烈礬縣・西迎赤石關門】，往東是堆滿廢料的【廢礬渣堆與私銅暗窖】，\n"
             "往南則有一條隱蔽山徑切入通往濁水縣的【東麓峽谷私梟道】（210 里）。\n");

    set_exits(([
        "north": "/d/counties/liefan/west_gate.c",
        "east":  "/d/counties/liefan/hongsha_slag.c",
        "south": "/d/routes/east_ravine_smuggler.c",
    ]));

    set_coordinate(6, 12, 0);
}
