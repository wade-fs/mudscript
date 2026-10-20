// /d/counties/zhongshi/post_inn.c
// 重石縣 (Zhongshi County) 房間 5/14：重石縣驛・磐石騾馬店

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣驛・磐石騾馬店");
    set_long("寬闊的石砌院落內拴著數十匹骨架粗大的西南挽馬與健騾，專供拖曳萬斤條石\n"
             "大車北上府城之用。店堂內酒香與汗味交雜，幾名從落龍西谷棧道驚魂未定趕來的\n"
             "行客正大口喝著熱湯壓驚。向西北出院即回【石鐵大集】。\n");

    set_exits(([
        "northwest": "/d/counties/zhongshi/market.c",
    ]));

    set_has_tavern(1);
    set_is_outdoor(0);
    set_coordinate(-2, 5, 0);
}
