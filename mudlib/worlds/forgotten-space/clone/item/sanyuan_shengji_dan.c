// /clone/item/sanyuan_shengji_dan.c
// 三元生機丹與西台試毒銀針雙盲封樣組（第三卷 Ch.113 問道天台百工丹器雙絕試）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("三元生機丹暨試毒封樣", ({ "sanyuan_shengji_dan", "shengji_dan", "三元生機丹", "試毒封樣" }));
    set_short(HIG "「三元生機丹」暨雙盲銀針封樣" NOR);
    set_long("顧玄在問道天台西側丹鼎藥試台以粗泥小藥爐煉出的三顆淡青色無瑕「三元生機丹」，\n"
             "旁附雙層玻璃封樣罐——盛有李青雲所煉「九轉增元丹」插針兩息即冒灰黑煙並生暗紫鏽斑之\n"
             "純銀試針與兩片瞬間枯死之雪線苔活葉；另有「紅血引子（百年赤參精髓）」待核檢領料簿。\n");
    set_weight(160);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
