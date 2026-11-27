// /d/counties/liefan/dihuo_fort.c
// 烈礬縣 (Liefan County) 房間 11/14：地火堡・窯工聚落 (轄下新手村 2，對應卷二 Ch.63)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("地火堡・耐火窯工聚落");
    set_long("這座建在天然地火裂隙群上的石堡聚落，地面終年溫熱，冬不積雪。堡內\n"
             "世代居住著精通耐火白泥配方與高溫粗陶燒製的窯工家族。向南可返回【烈礬縣・西迎赤石關門】，\n"
             "往北穿過磚拱門便是晝夜火光映天的【地火堡・三座官造耐火大窯】。\n");

    set_exits(([
        "south": "/d/counties/liefan/west_gate.c",
        "north": "/d/counties/liefan/dihuo_kiln.c",
    ]));

    set_coordinate(6, 14, 0);
}
