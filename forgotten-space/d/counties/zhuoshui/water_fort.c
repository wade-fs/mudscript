// /d/counties/zhuoshui/water_fort.c
// 濁水縣 (Zhuoshui County) 房間 7/15：濁水護澤武館・八方武館水路分舵 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("濁水護澤武館・八方分舵");
    set_long("這座建在巨型連環木筏與高腳椿台上的水寨武館，校場由碗口粗的鐵索串聯\n"
             "浮木而成，隨波起伏不定。八方武館駐濁水分舵主【彭鐵槳】正率領弟子手持百斤熟鐵\n"
             "長槳演練水上拔樁與浮橋爭鋒之術。有志於【力】道的行者可在此申請地方初階考核\n"
             "（輸入 exam 或 考取），獲發與都城武館完全等效之【註冊武館／鏢師黑鐵腰牌】。\n"
             "向西走過木橋即回【北鎮高腳木樁門】。\n");

    set_exits(([
        "west": "/d/counties/zhuoshui/north_gate.c",
    ]));

    set_has_guild(1);
    set_coordinate(7, 7, 0);
}
