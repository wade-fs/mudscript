// /d/counties/zhongshi/watermill_forge.c
// 重石縣 (Zhongshi County) 房間 11/14：石碾坡・水磨生鐵工坊 (30天衝突線：水力與工傷)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("石碾坡・水磨生鐵工坊");
    set_long("湍急的引水石渠在此驅動三具直徑兩丈的巨型水輪，帶動沉重的生鐵水排\n"
             "與碎礦石碾日夜轟鳴。然而自從穿山寨採石場為趕製都城急徵條石而在上游截流洗石，\n"
             "水磨坊的水輪轉速大減，幾名滿臉煤灰的冶鐵匠人正憤怒地拎著鐵錘準備找石頭幫理論。\n"
             "向北可返回【石碾坡・生鐵匠村】。\n");

    set_stage_desc(1, "上游穿山寨截流洗石導致水排風力不足，兩座生鐵高爐被迫減產。");
    set_stage_desc(2, "三號絞盤崩斷消息傳來，黑鐵砂篩洗停頓，武館催貨差役與鐵匠在坊外爭執。");
    set_stage_desc(3, "工傷撫恤遭剋扣的民夫聯合水磨坊鐵匠罷工，生鐵錠與黑鐵砂行情暴漲！");
    set_stage_desc(4, "魯長生弟子修妥絞盤並重新分攤水渠流量，水輪恢復轟鳴運轉。");

    set_exits(([
        "north": "/d/counties/zhongshi/shinian_slope.c",
    ]));

    set_has_forge(1);
    set_coordinate(-2, 3, 0);
}
