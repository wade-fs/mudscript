// /d/counties/panmu/carpentry_shed.c
// 盤木縣 (Panmu County) 房間 6/14：天工木作工棚・百工機巧分舵 (【物】道等效資格考場，卷二 Ch.42)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_branch_org("org_baigong");
    set_qual_path("wu");
    set_short("天工木作工棚・百工分舵");
    set_long("這座挑高三丈的巨型木作工棚乃府城百工總會駐盤木縣之機巧與大木作分舵。\n"
             "棚內架設著精密的水力帶動大鋸、滑輪組與剛修復不久的重型集材絞盤（Ch.42）。\n"
             "百工總會大木作司匠魯長生之弟【魯長林】坐鎮於此，凡通曉物性應力與木作機巧之\n"
             "學徒，均可在此參加地方初階匠籍考核（輸入 exam 或 考取），直接獲發與府城總會\n"
             "完全等效之【百工正式匠籍】。向西返回【木革山貨集】，往東通往【鞣革與松煙符紙坊】。\n");

    set_exits(([
        "west": "/d/counties/panmu/market.c",
        "east": "/d/counties/panmu/tannery_mill.c",
    ]));

    set_has_forge(1);
    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(4, 6, 0);
}
