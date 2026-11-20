// /d/yunjin/western_warehouse_street.c
// 雲津仙集・西街貨棧區 (Ch.84, Ch.90)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・西街貨棧區");
    set_long("條石鋪成的貨運長街，兩旁林立著掛滿商號木牌的大小石砌貨棧，不時可見\n"
             "披著霜雪的雪橇車隊卸下來自金石府六縣的耐火炭袋、乾草與生鐵軸。\n"
             "街尾那座原本漏風、如今修葺整齊的小型石砌舊貨棧掛著一塊黑墨寫成的【泥途商棧】木牌。\n"
             "往東返回【萬山廣場】，向西步入【泥途商棧】，向南拐入繁鬧的【三宗物資交易街】。\n");

    set_exits(([
        "east":  "/d/yunjin/wanshan_square.c",
        "west":  "/d/yunjin/mudway_store.c",
        "south": "/d/yunjin/three_sect_market.c",
    ]));

    set("is_outdoor", 1);
}
