// /d/counties/liefan/west_gate.c
// 烈礬縣 (Liefan County) 房間 1/14：西迎赤石關門 (對應卷二 Ch.63)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("烈礬縣・西迎赤石關門");
    set_long("這座依孤狼嶺紅石斷脈而建的礦冶縣城，城牆全由暗紅色的耐火砂岩砌築，\n"
             "空氣中終年瀰漫著一股酸澀的明礬與硫磺煙氣。城門下設有三座官辦過磅銅秤，嚴查\n"
             "出境的赤銅錠與硝石批文。向西南出關即入【礬石峽谷・苦泉茶棚】（320 里通東關），\n"
             "往東入城直達【銅礬硃砂大集】，往南通往【紅砂坳】，往北則是【地火堡】。\n");

    set_exits(([
        "southwest": "/d/routes/alum_canyon_post.c",
        "east":      "/d/counties/liefan/market.c",
        "south":     "/d/counties/liefan/hongsha_hollow.c",
        "north":     "/d/counties/liefan/dihuo_fort.c",
    ]));

    set_coordinate(6, 13, 0);
}
