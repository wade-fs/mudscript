// /d/counties/panmu/pawnshop.c
// 盤木縣 (Panmu County) 房間 4/14：通寶當鋪・盤木分號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("通寶當鋪・盤木分號");
    set_long("高逾六尺的鐵木櫃台後方，通寶當鋪盤木分號的朝奉正撥動算盤，核算著\n"
             "今歲大木林班的預支銀票與熟革抵押契。牆角鐵架上掛著成捆的上等狼毫與老山參\n"
             "質押包。向東北推門而出即回【木革山貨集】。\n");

    set_exits(([
        "northeast": "/d/counties/panmu/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(2, 5, 0);
}
