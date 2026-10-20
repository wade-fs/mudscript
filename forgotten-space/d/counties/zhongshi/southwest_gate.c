// /d/counties/zhongshi/southwest_gate.c
// 重石縣 (Zhongshi County) 房間 1/14：西南巨石甕城

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石縣・西南巨石甕城");
    set_long("重石縣的城牆全由數千斤重的青黑花崗條石乾砌而成，稜角粗獷雄渾。\n"
             "這座西南甕城扼守著落龍西谷棧道的出山口，門洞地面被鐵輪大車與搬石力士的\n"
             "草鞋磨得光滑如鏡。向南出城即踏上驚險的【落龍西谷・懸崖飛棧】（通往黑石鋪），\n"
             "往東北入城直達【重石石鐵大集】，往東南山坡則通往生鐵匠人聚居的【石碾坡】。\n");

    set_exits(([
        "south":     "/d/routes/cliff_broken_plank.c",
        "northeast": "/d/counties/zhongshi/market.c",
        "southeast": "/d/counties/zhongshi/shinian_slope.c",
    ]));

    set_coordinate(-3, 5, 0);
}
