// /d/counties/qinghe/drill_ground.c
// 青河縣 (Qinghe County) 房間 8/14：青河水師營校場・八方武館協訓 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("青河水師營・八方協訓校場");
    set_long("這座緊鄰青河岸邊的夯土大校場上，除了排列整齊的石鎖與木人樁外，還\n"
             "架設著數具模擬平底漕船搖晃甲板的「浪木樁陣」。八方武館駐青河總教頭【江萬濤】\n"
             "正督導水路護航武卒演練踏浪樁功與鐵槳搏殺。有志於【力】道的行者可在此申請\n"
             "地方初階考核（輸入 exam 或 考取），獲發與都城武館完全等效之【註冊武館／鏢師黑鐵腰牌】。\n"
             "往南出營即回【東迎水陸關門】。\n");

    set_exits(([
        "south": "/d/counties/qinghe/east_gate.c",
    ]));

    set_has_guild(1);
    set_coordinate(-7, 11, 0);
}
