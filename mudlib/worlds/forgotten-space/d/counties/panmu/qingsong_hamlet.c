// /d/counties/panmu/qingsong_hamlet.c
// 盤木縣 (Panmu County) 房間 11/14：青松塢・獵戶山村

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("青松塢・獵戶山村");
    set_long("這座藏於蒼翠松林間的獵戶村落由十幾座原木吊腳屋組成，屋簷下掛滿了\n"
             "風乾的野鹿肉與山狸皮。青松塢世代依靠周邊古林屏障阻擋大荒外圍走獸，近來卻\n"
             "因商會林班越界砍伐老樹而與伐木隊關係劍拔弩張。往西北山徑返回【盤木縣南門】，\n"
             "向東則進入村外布防的【獵場防獸陷阱帶】。\n");

    set_exits(([
        "northwest": "/d/counties/panmu/south_gate.c",
        "east":      "/d/counties/panmu/qingsong_traps.c",
    ]));

    set_coordinate(4, 4, 0);
}
