// /d/counties/qinghe/luhuadu_shoal.c
// 青河縣 (Qinghe County) 房間 12/14：蘆花渡古河床・史前石閘殘件 (對應卷二 Ch.59 & Stage 4 奇遇線索入口)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("蘆花渡古河床・史前石閘殘件");
    set_long("這是青河故道的一處偏僻泥沙淺灘，河床淤泥下隱約露出半截巨大無比、\n"
             "表面呈現暗青色金屬質感的史前石閘基座。石閘導槽並非大乾工匠常用的燕尾榫，\n"
             "而是精密得令人心悸的螺旋止水齒紋，與黑石鋪溪底逆星斷碑及重石台地石槨同屬\n"
             "太古九城外圍水利陣基。往北可返回【蘆花渡・漁農草集】。\n");

    set_stage_desc(1, "由於上游截水導致下游水位大降，原本深埋水底的史前石閘頂端首次露出水面。");
    set_stage_desc(4, "副渠洩洪的湍急水流沖走了千年淤沙，完整顯露出史前石閘上的太古水文星宿刻度！");

    set_exits(([
        "north": "/d/counties/qinghe/luhuadu_dock.c",
    ]));

    add_item("sluice_relic", "半截嵌入古河床岩盤的史前暗青石閘殘件，表面刻著精密的螺旋止水紋與星宿水尺。");
    set_coordinate(-8, 7, 0);
}
