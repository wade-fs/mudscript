// /d/counties/zhongshi/terrace_trench.c
// 重石縣 (Zhongshi County) 房間 14/14：重石台地深溝・太古石槨氣孔 (Stage 4 奇遇線索入口)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("重石台地深溝・太古石槨氣孔");
    set_long("順著採石場底部開鑿出的三十丈深溝下探，四周花崗岩層逐漸轉為一種非金\n"
             "非石的暗青色結晶岩壁。深溝盡頭露出半截被地殼擠壓變形的「太古巨型石槨」邊角，\n"
             "石縫間正緩緩噴吐出沉重如汞的玄黃地脈煞氣，岩壁上隱約可見史前陣列蝕刻的\n"
             "幾何斷紋（對應卷三太古陣列伏筆）。向上攀爬 (up) 可返回【三號絞盤採石場】。\n");

    set_stage_desc(4, "深溝底部的太古石槨氣孔正與地脈產生低頻共鳴，吸引著具高感知或天命之行者探查。");

    set_exits(([
        "up": "/d/counties/zhongshi/quarry_winch3.c",
    ]));

    add_item("sarcophagus", "半截嵌入深層岩盤的太古石槨，表面刻著不屬於大乾文字體系的幾何陣列凹槽。");
    set_is_outdoor(0);
    set_coordinate(0, 6, -1);
}
