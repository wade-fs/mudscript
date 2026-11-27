// /d/counties/liefan/pawnshop.c
// 烈礬縣 (Liefan County) 房間 4/14：通寶當鋪・烈礬分號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("通寶當鋪・烈礬分號");
    set_long("包鐵黑漆高櫃後方，烈礬分號朝奉正撥動銅算盤，為資金鏈斷裂的紅砂坳\n"
             "小礦主辦理礦權抵押，同時憑通寶總號信印調撥高純明礬硃砂晶與耐火料批單。自從\n"
             "黑石鋪血精停產導致本地熔煉助劑暴跌後，不少礦主全靠此處拆借度日。向東北推門\n"
             "即回【銅礬硃砂大集】。\n");

    set_exits(([
        "northeast": "/d/counties/liefan/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(6, 12, 0);
}
