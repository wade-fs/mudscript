// /d/counties/liefan/tongtuo_shaft3.c
// 烈礬縣 (Liefan County) 房間 14/14：銅駝嶺三號深井・地火毒煙裂隙 (對應卷二 Ch.63 排毒煙救礦工 & 30天 Stage 3)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("銅駝嶺三號深井・地火裂隙");
    set_long("深入地底數十丈的三號主礦井內悶熱如蒸籠，赤紅岩壁被違規過量的硝石\n"
             "炸藥震出數道深不可測的地火裂隙，刺鼻的硫磺酸霧與地火毒煙正不斷外洩。唯有\n"
             "懂得百工通風機括與生石灰濕巾濾毒之法，方能在此排煙搶險。順木梯向上 (up) 可返回\n"
             "地面【銅駝嶺・赤銅伴生礦區】。\n");

    set_stage_desc(3, "私爐礦工為趕黑市急單違規過量爆破，引發三號深井地火毒煙外洩與局部塌方，硝石暴漲！");

    set_exits(([
        "up": "/d/counties/liefan/tongtuo_ridge.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(9, 13, -1);
}
