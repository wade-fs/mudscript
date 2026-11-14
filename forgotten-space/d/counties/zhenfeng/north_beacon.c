// /d/counties/zhenfeng/north_beacon.c
// 鎮風縣 (Zhenfeng County) 房間 10/14：北塞防風石壩・望荒狼煙烽燧 (對應卷二 Ch.62 & 30天 Stage 3)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("北塞防風石壩・望荒烽燧");
    set_long("這是鎮風縣最北端的巨型防風石壩與三丈高的狼煙烽燧台。站在垛口向北\n"
             "極目遠眺，便是蒼茫死寂、寒風呼嘯的極北雪原與大荒天塹。烽燧台上堆放著拌有\n"
             "硫磺與狼糞的乾柴垛，的值守老卒裹著厚重的羊皮襖，目光如鷹隼般巡視著雪原邊際。\n"
             "往南下壩可返回【皮甲硬弓邊集】。\n");

    set_stage_desc(3, "外圍三號烽燧昨夜遭外荒雪狼群試探性夜襲，垛口留著焦黑火痕與斑斑血跡，全線進入最高戰備！");

    set_exits(([
        "south": "/d/counties/zhenfeng/market.c",
    ]));

    set_coordinate(0, 18, 0);
}
