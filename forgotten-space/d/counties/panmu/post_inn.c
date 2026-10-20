// /d/counties/panmu/post_inn.c
// 盤木縣 (Panmu County) 房間 5/14：盤木縣驛・聽松客棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣驛・聽松客棧");
    set_long("這座寬敞的兩層木樓既是官設盤木縣驛，也是往來黑石鋪與金石府城商旅\n"
             "必經的落腳客棧。大堂中央燒著一盆火紅的松球炭火，幾名剛從虎跳峽趕路至此的\n"
             "趟子手正烘烤著被露水打濕的綁腿。向西北出門便是【木革山貨集】。\n");

    set_exits(([
        "northwest": "/d/counties/panmu/market.c",
    ]));

    set_has_tavern(1);
    set_is_outdoor(0);
    set_coordinate(4, 5, 0);
}
