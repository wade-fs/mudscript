// /d/counties/zhongshi/chuanshan_camp.c
// 重石縣 (Zhongshi County) 房間 12/14：穿山寨・石工聚落

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_short("穿山寨・石工聚落");
    set_long("這座依託半山斷崖建立的石工大寨聚集了數百名膀大腰圓的開山石匠與\n"
             "「穿山石頭幫」力夫。寨內地面鋪滿了青白色石屑，隨處可見磨得雪亮的開山鋼钎、\n"
             "千斤頂木楔與搬運條石的滾木架。往西返回【重石石作總坊】，向北直通【穿山力士堂】，\n"
             "向東深入斷崖台地便是核心作業區【三號巨型絞盤採石場】。\n");

    set_exits(([
        "west":  "/d/counties/zhongshi/stone_guild.c",
        "north": "/d/counties/zhongshi/crusher_hall.c",
        "east":  "/d/counties/zhongshi/quarry_winch3.c",
    ]));

    set_coordinate(-1, 6, 0);
}
