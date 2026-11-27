// /d/counties/zhongshi/quarry_winch3.c
// 重石縣 (Zhongshi County) 房間 13/14：穿山寨・三號巨型絞盤採石場 (卷二 Ch.66 & 30天 Stage 2~4 現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("穿山寨・三號絞盤採石場");
    set_long("高達十丈的階梯狀採石斷崖下，矗立著一具由百工總會設計的「三號巨型\n"
             "天工絞盤」，碗口粗的生鐵鏈條正吊起萬斤重的重玄城防條石。自從黑石鋪配額轉嫁\n"
             "至此，絞盤超負荷日夜運轉，齒輪軸承發出刺耳的摩擦尖嘯。向西返回【穿山寨】，\n"
             "往崖底裂口向下 (down) 則可探入新近開鑿切穿的【重石台地深溝】。\n");

    set_stage_desc(1, "三號巨型絞盤正日夜超負荷吊運急徵條石，生鐵軸承已被磨得發紅。");
    set_stage_desc(2, "三號絞盤主軸齒輪崩斷！半空落下的萬斤條石砸塌木架，採石作業全面停擺。");
    set_stage_desc(3, "受傷石工家屬圍堵採石場討要撫恤，城防條石斷供導致價格飆漲至 170%！");
    set_stage_desc(4, "百工總會換上新鍛赤銅軸承修妥絞盤，深層開鑿卻意外切穿了台地底部的太古氣孔。");

    set_exits(([
        "west": "/d/counties/zhongshi/chuanshan_camp.c",
        "down": "/d/counties/zhongshi/terrace_trench.c",
    ]));

    set_coordinate(0, 6, 0);
}
