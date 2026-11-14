// /d/counties/zhenfeng/wind_altar.c
// 鎮風縣 (Zhenfeng County) 房間 7/14：鎮風測風祭壇・宣道司邊塞觀象所 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("鎮風測風祭壇・邊塞觀象所");
    set_long("這座聳立於縣城西側高崖上的八角青石祭壇，中央架設著由高純風蝕石英\n"
             "磨製而成的巨型「定風透鏡」與銅製相風烏。宣道司外派觀象道官【凌風子】在此\n"
             "常年測算極北寒潮與罡風煞氣的演變軌跡。有志於【法】道的行者可在此申請地方\n"
             "初階度牒考核（輸入 exam 或 考取），獲發與都城宣道司完全等效之【大乾觀象受牒度牒】。\n"
             "往南下階可返回【鎮風縣衛所】。\n");

    set_exits(([
        "south": "/d/counties/zhenfeng/yamen.c",
    ]));

    set_has_guild(1);
    set_coordinate(-1, 18, 0);
}
