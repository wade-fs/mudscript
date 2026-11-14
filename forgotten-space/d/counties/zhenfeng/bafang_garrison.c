// /d/counties/zhenfeng/bafang_garrison.c
// 鎮風縣 (Zhenfeng County) 房間 8/14：八方武館邊關分舵・重弓演武堂 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("八方武館邊關分舵・重弓堂");
    set_long("這座氣勢雄渾的巨石演武堂內，一字排開十餘張需三石氣力方能拉滿的\n"
             "牛角筋胎重弓，遠處百步外立著包鐵厚木靶。八方武館邊關分舵主【秦烈風】常年\n"
             "在此主持軍陣重弓與破甲樁功實戰考核。有志於【力】道的行者可在此申請地方初階\n"
             "考核（輸入 exam 或 考取），獲發與都城武館完全等效之【註冊武館／鏢師黑鐵腰牌】。\n"
             "向西出堂回【皮甲硬弓邊集】，往北通往【鎮風軍械修造所】。\n");

    set_exits(([
        "west":  "/d/counties/zhenfeng/market.c",
        "north": "/d/counties/zhenfeng/tannery.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(1, 17, 0);
}
