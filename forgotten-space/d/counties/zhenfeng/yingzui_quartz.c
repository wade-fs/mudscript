// /d/counties/zhenfeng/yingzui_quartz.c
// 鎮風縣 (Zhenfeng County) 房間 12/14：天風谷鷹嘴崖・風蝕石英礦脈 (對應卷二 Ch.61 頂風採擷高純風蝕石英)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("天風谷鷹嘴崖・風蝕石英礦脈");
    set_long("立於百丈危崖之巔，極北吹來的九天罡風如刀刃般呼嘯刮過！裸露的黑曜\n"
             "岩壁裂隙中，鑲嵌著一簇簇歷經千年罡風打磨、純淨無瑕的六稜【高純風蝕石英】——\n"
             "這正是宣道司打磨觀星透鏡與百工製作精密儀器的核心奇材。順著鐵索向下 (down)\n"
             "可退回安全的【鷹嘴崖・散人避風石窟】。\n");

    set_exits(([
        "down": "/d/counties/zhenfeng/yingzui_cliff.c",
    ]));

    add_item("quartz_vein", "歷經極北罡風千年吹蝕而成的六稜高純石英礦脈，折光率極為驚人。");
    set_coordinate(-1, 16, 1);
}
