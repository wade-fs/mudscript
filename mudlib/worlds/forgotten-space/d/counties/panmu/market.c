// /d/counties/panmu/market.c
// 盤木縣 (Panmu County) 房間 2/14：木革山貨集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣・木革山貨集");
    set_long("盤木縣的中央市集鋪設著厚實的鐵木橫木板，空氣中瀰漫著濃烈的松脂、\n"
             "熟牛皮與山林野味氣息。來自大荒邊緣的獵戶與木客在此交易千年鐵木芯、冷杉樹脂、\n"
             "整張山狼皮與鞣製革料。北面通往【北望木城樓】，南面是【南林柵門】，西側為\n"
             "【盤木縣衙】，東側傳來陣陣鋸木與機括聲響的是【天工木作工棚】，西南與東南則\n"
             "分別坐落著【通寶當鋪盤木分號】與【盤木縣驛】。\n");

    set_exits(([
        "south":     "/d/counties/panmu/south_gate.c",
        "north":     "/d/counties/panmu/north_gate.c",
        "west":      "/d/counties/panmu/yamen.c",
        "east":      "/d/counties/panmu/carpentry_shed.c",
        "southwest": "/d/counties/panmu/pawnshop.c",
        "southeast": "/d/counties/panmu/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(3, 6, 0);
}
