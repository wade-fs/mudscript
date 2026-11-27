// /d/counties/panmu/tannery_mill.c
// 盤木縣 (Panmu County) 房間 7/14：盤木鞣革與松煙符紙坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木鞣革與松煙符紙坊");
    set_long("工坊前半院整齊排列著數十口浸泡山獸皮張的橡木硝皮大缸，後半院則利用\n"
             "陳年冷杉松煙與青檀樹皮抄造專供宣道司繪符所用的「松煙韌符紙」。幾名皮匠與\n"
             "紙工正忙著將晾乾的熟革與符紙打捆裝箱。向西可返回【天工木作工棚】。\n");

    set_exits(([
        "west": "/d/counties/panmu/carpentry_shed.c",
    ]));

    set_has_lab(1);
    set_coordinate(5, 6, 0);
}
