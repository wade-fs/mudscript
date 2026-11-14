// /d/counties/zhuoshui/north_gate.c
// 濁水縣 (Zhuoshui County) 房間 1/15：北鎮高腳木樁門 (對應卷二 Ch.64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("濁水縣・北鎮高腳木樁門");
    set_long("這座建於怒龍江支流沼澤泥灘上的奇特縣城，全城皆由粗大的桐油鐵木高腳\n"
             "樁凌空架起，底下便是翻滾著赭黃泥漿與毒瘴氣泡的爛泥灘。木樁城門上懸掛著辟瘴\n"
             "銅鈴。向西北踏上浮橋可通【高腳木樁浮橋・水瘴哨卡】（350 里通東關），往南入城\n"
             "直達【浮橋金砂水集】，往西下坡為【泥螺灘】，往東則是【濁水護澤武館】。\n");

    set_exits(([
        "northwest": "/d/routes/pontoon_toll_post.c",
        "south":     "/d/counties/zhuoshui/market.c",
        "west":      "/d/counties/zhuoshui/niluo_shoal.c",
        "east":      "/d/counties/zhuoshui/water_fort.c",
    ]));

    set_coordinate(6, 7, 0);
}
