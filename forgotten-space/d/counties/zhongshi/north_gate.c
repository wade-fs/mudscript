// /d/counties/zhongshi/north_gate.c
// 重石縣 (Zhongshi County) 房間 9/14：北鎮條石關門

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣・北鎮條石關門");
    set_long("雄偉的雙孔石拱北門以整塊萬斤重玄巨石作門楣，門洞兩側設有官防條石\n"
             "過磅地秤。一列列載滿城防條石與粗生鐵錠的重型大車由此出城，駛上通往金石府城\n"
             "的西南條石馳道。往南直達【重石石鐵大集】，西面是【重石測脈亭】，東面為\n"
             "【穿山力士堂】，向東北出城即抵【西南條石馳道・車轍接官亭】（240 里）。\n");

    set_exits(([
        "south":     "/d/counties/zhongshi/market.c",
        "west":      "/d/counties/zhongshi/leyline_pavilion.c",
        "east":      "/d/counties/zhongshi/crusher_hall.c",
        "northeast": "/d/routes/stone_highway_pavilion.c",
    ]));

    set_coordinate(-3, 7, 0);
}
