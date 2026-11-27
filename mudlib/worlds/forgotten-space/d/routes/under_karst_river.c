// /d/routes/under_karst_river.c
// 地下溶洞暗河 (seg_city_zhuoshui_under, 310里) 節點 1：磷苔水道 (對應卷二 Ch.64-65)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhuoshui_under");
    set_node_index(1);
    set_short("地下溶洞暗河・磷苔水道");
    set_long("這條位於地底十餘丈深處的天然喀斯特溶洞暗河，接駁著金石府城古暗渠\n"
             "與東南濁水河網。岩壁上長滿散發幽綠微光的磷火青苔，陰冷的暗河水無聲流淌。\n"
             "此處完全處於宣道司絕靈法網盲區，唯有輕舟或步涉棧橋可通（禁快馬）。向西北回\n"
             "【城下暗渠・水網樞紐】，往東南順暗流可抵【鐘乳暗渦洞】。\n");

    set_exits(([
        "northwest": "/d/city/under/canal_hub.c",
        "southeast": "/d/routes/under_whirlpool_cave.c",
    ]));

    set_is_outdoor(0);
    set("is_underground", 1);
    set_coordinate(3, 8, -1);
}
