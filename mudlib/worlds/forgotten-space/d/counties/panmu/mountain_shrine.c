// /d/counties/panmu/mountain_shrine.c
// 盤木縣 (Panmu County) 房間 8/14：盤木山神廟・宣道司外派駐點 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("盤木山神廟・望氣講堂");
    set_long("這座古樸的山神廟依附在一株三人合抱的千年冷杉古樹下，廟內除了供奉\n"
             "南嶺山神石像外，西廂還設有金石府宣道司外派的「山林望氣駐點」。宣道司外派\n"
             "道長【古木真人】常年在此觀測南嶺林海的地脈煞氣與獸潮徵兆。求法弟子若能\n"
             "於松濤山霧裡辨清靈機流向，便可就地請考（輸入 exam 或 考取），由古木真人點定\n"
             "【大乾觀象受牒度牒】，效力與府城宣道本壇無異。往南下階回【盤木縣衙】，向東通往【北望木城樓】。\n");

    set_exits(([
        "south": "/d/counties/panmu/yamen.c",
        "east":  "/d/counties/panmu/north_gate.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(2, 7, 0);
}
