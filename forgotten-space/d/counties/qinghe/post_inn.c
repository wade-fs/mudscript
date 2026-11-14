// /d/counties/qinghe/post_inn.c
// 青河縣 (Qinghe County) 房間 6/14：青河縣驛・臨水客舍

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("青河縣驛・臨水客舍");
    set_long("這座二層竹木小樓依水而建，推開後窗便能聽見潺潺水聲與畫舫櫓聲。大堂\n"
             "內常有自都城西水門押船而來的鏢客與藥商歇腳，桌上擺著清熱祛濕的薄荷竹葉茶。\n"
             "向西北走出客舍即回【百草糧油水集】。\n");

    set_exits(([
        "northwest": "/d/counties/qinghe/market.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(-7, 9, 0);
}
