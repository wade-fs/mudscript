// /d/counties/zhongshi/shinian_slope.c
// 重石縣 (Zhongshi County) 房間 10/14：石碾坡・生鐵匠村

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("石碾坡・生鐵匠村");
    set_long("順著重石縣西南山坡向下，溪流兩岸密佈著數十座以片石壘成的匠戶石屋。\n"
             "空氣中瀰漫著煤煙與鐵鏽味，村民世代引山澗水力推動巨型石碾與水排鼓風爐，將\n"
             "原礦粉碎冶煉成粗生鐵錠與黑鐵砂。往西北上坡返回【西南巨石甕城】，向南沿溪\n"
             "而下則是村裡核心的【水磨生鐵工坊】。\n");

    set_exits(([
        "northwest": "/d/counties/zhongshi/southwest_gate.c",
        "south":     "/d/counties/zhongshi/watermill_forge.c",
    ]));

    set_coordinate(-2, 4, 0);
}
