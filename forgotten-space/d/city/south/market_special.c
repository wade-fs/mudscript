// d/city/south/market_special.c
// 六縣專材長街 (青河藥、烈礬銅硃砂、盤木木紙、鎮風弓、濁水金、重石鐵)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石都城・六縣專材長街");
    set_long("這條青石長街兩側排列著全府六大縣城的特產專營鋪席，幡旗招展，客商如織。\n"
             "西首陳列著青河洗靈草與盤木韌桑符紙，東首叫賣著烈礬赤銅硃砂晶與鎮風硬弓，\n"
             "重石生鐵農具與濁水淘金重晶石亦在街頭掛牌結算，匯聚全府物資流通動脈。\n"
             "向北直通中央青石廣場，往南通往大石堆棧，\n"
             "西面是氣勢恢弘的金石商會總堂，東面則是遠行車馬大院。\n");

    set_exits(([
        "north": "/d/city/center/square.c",
        "south": "/d/city/south/yard_material.c",
        "west":  "/d/city/south/shanghui_hq.c",
        "east":  "/d/city/south/caravan_yard.c",
    ]));

    set("is_outdoor", 1);
    set("has_shop", 1);
}
