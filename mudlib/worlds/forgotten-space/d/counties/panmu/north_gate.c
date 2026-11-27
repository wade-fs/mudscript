// /d/counties/panmu/north_gate.c
// 盤木縣 (Panmu County) 房間 10/14：北望木城樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣・北望木城樓");
    set_long("高聳的三層鐵木城樓扼守著盤木縣北上金石府城的林海官道要衝。城門兩側\n"
             "設有利箭射孔與滾木擂石架，車馬大院的押鏢趟子手在此查驗北上木排與革料車隊的\n"
             "封條。往南直通【木革山貨集】，西面是【盤木山神廟】，東面為【巡山獵武堂】，\n"
             "向北出城則踏上通往府城的【南嶺林海驛】（260 里）。\n");

    set_exits(([
        "south": "/d/counties/panmu/market.c",
        "west":  "/d/counties/panmu/mountain_shrine.c",
        "east":  "/d/counties/panmu/hunter_lodge.c",
        "north": "/d/routes/forest_sea_post.c",
    ]));

    set_coordinate(3, 7, 0);
}
