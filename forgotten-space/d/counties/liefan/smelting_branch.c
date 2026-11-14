// /d/counties/liefan/smelting_branch.c
// 烈礬縣 (Liefan County) 房間 8/14：烈礬百工冶煉分舵・官辦耐火總坊 (【物】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_branch_org("org_baigong");
    set_qual_path("wu");
    set_short("烈礬百工冶煉分舵・耐火總坊");
    set_long("高達三丈的引風煙囪下，數座官辦地火熔銅爐正噴吐著青白烈焰，滾燙的\n"
             "赤銅水順著耐火泥槽流入錠模。百工總會外派分舵主【歐陽炎】在此統管全縣赤銅冶煉\n"
             "與高純耐火料調撥。有志於【物】道的行者可在此參加考核（輸入 exam 或 考取），\n"
             "獲發與都城百工總會完全等效之【百工正式匠籍】。向西回【銅礬硃砂大集】，往東則\n"
             "通往礦脈核心【孤狼嶺（銅駝嶺）赤銅礦區】。\n");

    set_exits(([
        "west": "/d/counties/liefan/market.c",
        "east": "/d/counties/liefan/tongtuo_ridge.c",
    ]));

    set_has_guild(1);
    set_has_forge(1);
    set_is_outdoor(0);
    set_coordinate(8, 13, 0);
}
