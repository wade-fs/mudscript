// /d/counties/panmu/yamen.c
// 盤木縣 (Panmu County) 房間 3/14：盤木縣衙・山林撫民署

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣衙・山林撫民署");
    set_long("盤木縣衙由整根去皮冷杉搭建，正堂懸掛著「撫山安林」匾額。堂前廊下\n"
             "堆滿了關於倒影澗林班越界砍伐與青松塢獵戶防獸陷阱損毀的申訴狀紙。幾名背著\n"
             "獵弓的縣衙差役正神色凝重地核對山林地契。向東返回【木革山貨集】，往北拾級\n"
             "而上則是供奉古山神的【盤木山神廟】。\n");

    set_exits(([
        "east":  "/d/counties/panmu/market.c",
        "north": "/d/counties/panmu/mountain_shrine.c",
    ]));

    set_no_combat(1);
    set_is_outdoor(0);
    set_coordinate(2, 6, 0);
}
