// /d/counties/zhongshi/yamen.c
// 重石縣 (Zhongshi County) 房間 3/14：重石縣衙・督石官署

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣衙・督石官署");
    set_long("厚重的青石大堂內擺著一尊丈許寬的《重石台地礦脈全圖》石盤。自從黑石鋪\n"
             "北崖塌方後，金石府衙將都城官防條石急徵令全數轉嫁至重石縣，縣丞與督石典史\n"
             "正為穿山寨採石場與石碾坡水磨坊爭搶水力、以及絞盤搶工工傷撫恤焦頭爛額。\n"
             "向東返回【石鐵大集】，往北登高則是宣道司外派的【重石測脈亭】。\n");

    set_exits(([
        "east":  "/d/counties/zhongshi/market.c",
        "north": "/d/counties/zhongshi/leyline_pavilion.c",
    ]));

    set_no_combat(1);
    set_is_outdoor(0);
    set_coordinate(-4, 6, 0);
}
