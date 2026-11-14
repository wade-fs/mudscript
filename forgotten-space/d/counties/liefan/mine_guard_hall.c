// /d/counties/liefan/mine_guard_hall.c
// 烈礬縣 (Liefan County) 房間 7/14：烈礬護礦武館・八方武館分舵 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("烈礬護礦武館・八方分舵");
    set_long("演武場四周擺滿了百斤重的赤銅巨鎖與灌滿紅砂的鐵皮樁，十餘名精赤上身\n"
             "的護礦武卒正頂著燥熱地氣演練剛猛霸道的劈山刀法。八方武館駐烈礬分舵主【雷震山】\n"
             "專司訓練押運官銅與鎮守硝石礦井的重甲護衛。有志於【力】道的行者可在此申請地方\n"
             "初階考核（輸入 exam 或 考取），獲發與都城武館完全等效之【註冊武館／鏢師黑鐵腰牌】。\n"
             "往北出館即回【銅礬硃砂大集】。\n");

    set_exits(([
        "north": "/d/counties/liefan/market.c",
    ]));

    set_has_guild(1);
    set_coordinate(7, 12, 0);
}
