// /d/counties/zhongshi/crusher_hall.c
// 重石縣 (Zhongshi County) 房間 7/14：重石穿山寨分館・八方武館力士堂 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("穿山力士堂・八方分舵");
    set_long("這座露天青石校場上擺滿了三百斤至八百斤不等的玄石鎖，數口大鐵鍋內\n"
             "正翻炒著滚燙的重石黑鐵砂。此處為八方行省武館在重石縣設立的「開山力士堂」，\n"
             "分舵總教頭【石霸天】正督導弟子以雙掌插入熱鐵砂中錘鍊『鐵砂淬骨』與『盤石樁功』。\n"
             "有志於【力】道之行者可在此參加地方初階武道考核（輸入 exam 或 考取），直接獲發\n"
             "等效之【八方黑鐵腰牌】。向西返回【北鎮條石關門】，往南通往【穿山寨】。\n");

    set_exits(([
        "west":  "/d/counties/zhongshi/north_gate.c",
        "south": "/d/counties/zhongshi/chuanshan_camp.c",
    ]));

    set_has_guild(1);
    set_coordinate(-2, 7, 0);
}
