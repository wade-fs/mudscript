// /d/counties/zhongshi/pawnshop.c
// 重石縣 (Zhongshi County) 房間 4/14：通寶當鋪・重石分號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("通寶當鋪・重石分號");
    set_long("整座當鋪如同石堡般堅不可摧，厚達三寸的生鐵柵欄後，掌櫃正收兌穿山寨\n"
             "石頭幫預押的條石提貨單與精鋼開山鑿。當三號絞盤發生工傷事故時，通寶重石分號\n"
             "亦常以墊支撫恤銀為條件收購民間採石場乾股。向東南出門即返【石鐵大集】。\n");

    set_exits(([
        "southeast": "/d/counties/zhongshi/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(-4, 7, 0);
}
