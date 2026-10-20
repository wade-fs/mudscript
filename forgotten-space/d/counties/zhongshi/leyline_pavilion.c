// /d/counties/zhongshi/leyline_pavilion.c
// 重石縣 (Zhongshi County) 房間 8/14：重石測脈亭・宣道司地脈勘驗所 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("重石測脈亭・觀象勘驗所");
    set_long("這座八角青石亭建於重石台地北側高埠之上，亭心地面鑲嵌著一具黃銅地動\n"
             "候風羅盤，下方直通深層岩脈。此處乃金石府宣道司外派之「地脈勘驗所」，主考\n"
             "道長【石璣道人】常年監測西南台地斷層與深溝煞氣外溢。有志於【法】道之行者\n"
             "可在此申請地方初階度牒考核（輸入 exam 或 考取），獲發與府城宣道司完全等效\n"
             "之【大乾觀象受牒度牒】。向南下坡返【重石縣衙】，往東通往【北鎮條石關門】。\n");

    set_exits(([
        "south": "/d/counties/zhongshi/yamen.c",
        "east":  "/d/counties/zhongshi/north_gate.c",
    ]));

    set_has_guild(1);
    set_coordinate(-4, 7, 1);
}
