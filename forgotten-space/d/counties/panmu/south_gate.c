// /d/counties/panmu/south_gate.c
// 盤木縣 (Panmu County) 房間 1/14：南林柵門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣・南林柵門");
    set_long("這座山林縣城的南門並非青磚砌就，而是由數十根合抱粗的百年鐵木原木\n"
             "削尖並排深埋入土，築成高逾兩丈的巨木寨牆。城門外便是通往虎跳峽與黑石鋪的\n"
             "山道，門洞下停靠著幾輛滿載巨木與獸皮的雙輪大車。向南出城可抵【盤木前驛站】，\n"
             "往北入城直通熱鬧的【木革山貨集】，往東南山徑則通往獵戶聚居的【青松塢】。\n");

    set_exits(([
        "south":     "/d/routes/panmu_post_approach.c",
        "north":     "/d/counties/panmu/market.c",
        "southeast": "/d/counties/panmu/qingsong_hamlet.c",
    ]));

    set_coordinate(3, 5, 0);
}
