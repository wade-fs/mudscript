// /d/counties/liefan/post_inn.c
// 烈礬縣 (Liefan County) 房間 5/14：烈礬縣驛・赤岩客舍

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("烈礬縣驛・赤岩客舍");
    set_long("這座紅砂岩砌築的驛館大院內停滿了裝載生銅錠與明礬桶的鐵輪大車。由於\n"
             "烈礬泉水多帶酸苦，店小二特意備有從南嶺運來的甘甜山泉與解毒綠豆湯。向西北\n"
             "步出院門即回【銅礬硃砂大集】。\n");

    set_exits(([
        "northwest": "/d/counties/liefan/market.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(8, 12, 0);
}
