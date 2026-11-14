// /d/counties/qinghe/herb_shrine.c
// 青河縣 (Qinghe County) 房間 7/14：定神靈植道觀・宣道司外派 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("定神靈植道觀・宣道司外派");
    set_long("這座掩映於翠竹與雲霧間的清幽道觀，乃金石府宣道司在青河上游設立的\n"
             "外圍靈植據點，專司培育供內城法道修士靜心除濁的「高階定神靈草」。宣道司外派\n"
             "道官【雲松道人】常年在此主持引水育靈與望氣講經。有志於【法】道的行者可在此\n"
             "申請地方初階度牒考核（輸入 exam 或 考取），獲發與都城宣道司完全等效之【大乾觀象受牒度牒】。\n"
             "往南下山可至道觀控管的【上游攔水濾沙石閘】。\n");

    set_exits(([
        "south": "/d/counties/qinghe/upper_dam.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(-10, 12, 0);
}
