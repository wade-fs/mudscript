// /d/counties/liefan/fire_shrine.c
// 烈礬縣 (Liefan County) 房間 6/14：烈礬鎮煞火祠・宣道司外派 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("烈礬鎮煞火祠・宣道司外派");
    set_long("這座建於地火氣孔正上方的赤色道祠，地面刻滿了疏導地底燥火的引靈陣紋，\n"
             "殿中長明銅爐內燃燒著永不熄滅的地脈真火。宣道司外派道官【赤陽道長】常年在此\n"
             "監測紅石斷脈的地火躁動，並提煉符道所需的明礬硃砂晶。有志於【法】道的行者可\n"
             "在此申請地方初階度牒考核（輸入 exam 或 考取），獲發與都城宣道司完全等效之\n"
             "【大乾觀象受牒度牒】。向東可返回【烈礬縣衙】。\n");

    set_exits(([
        "east": "/d/counties/liefan/yamen.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(6, 14, 0);
}
