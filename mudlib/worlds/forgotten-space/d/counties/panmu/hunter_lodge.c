// /d/counties/panmu/hunter_lodge.c
// 盤木縣 (Panmu County) 房間 9/14：盤木巡山獵武堂・八方武館分舵 (【力】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_branch_org("org_bafang");
    set_qual_path("li");
    set_short("巡山獵武堂・八方分舵");
    set_long("演武場四周插滿了包鐵硬木標槍與熊皮箭靶，這裡是八方行省武館在盤木縣\n"
             "設立的巡山獵武分舵。分舵主事【周獵虎】正赤膊督導十餘名巡山武卒練習鐵砂淬骨\n"
             "與重弓開弦。凡具氣血根骨之行者，皆可在此參加地方初階武道考核（輸入 exam 或 考取），\n"
             "獲發與府城武館完全等效之【八方黑鐵腰牌】。向西返回【北望木城樓】，往東則沿山溪\n"
             "深入【倒影澗・古林界碑】。\n");

    set_exits(([
        "west": "/d/counties/panmu/north_gate.c",
        "east": "/d/counties/panmu/daoying_stream.c",
    ]));

    set_has_guild(1);
    set_coordinate(4, 7, 0);
}
