// /clone/item/tool_star_observation_plate.c
// 星曆觀測校驗板暨《紫微星官錄》誤差摘錄（第三卷 Ch.91 藏星秘閣）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("星曆觀測校驗板", ({ "tool_star_observation_plate", "star observation plate", "observation plate", "星曆觀測校驗板", "校驗板" }));
    set_short(HIC "星曆觀測校驗板" NOR);
    set_long("一塊附有雙腳分規與炭筆誤差抄錄頁的黃銅校驗板，摘錄著《紫微星官錄》六百年前\n"
             "北境粗麻原測日誌與三百年前南境青檀宣紙修訂定本的對照數據：甲子大冬至夜相鄰七十餘\n"
             "星宿竟被同時順時針平推整整「一度半」。註：僅記紙墨年代與誤差，未證背後操控者。\n");
    set_weight(90);
    set_value(0);
    set("is_evidence", 1);
    set("is_tool", 1);
    set("evidence_grade", "corroborative");
}
