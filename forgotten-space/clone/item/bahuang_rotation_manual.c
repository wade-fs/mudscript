// /clone/item/bahuang_rotation_manual.c
// 《黑山分段輪替操典暨八十七人安置名冊》（第三卷 Ch.122：放棄血祭霸體，立分段守關新律）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑山輪替操典", ({ "bahuang_rotation_manual", "rotation_manual", "黑山分段輪替操典", "輪替操典" }));
    set_short(HIR "八荒黑山營・《分段輪替操典暨八十七人安置名冊》" NOR);
    set_long("燕隼與雷烈、岳停山、杜青禾、阿滿於黑山長城修復工地共同定稿的軍制與撫恤合冊：\n"
             "前冊整合戰神遺塚「長呼吸節律與氣血分段鎖儲法」、顧玄溫和降燥草藥與杜青禾病理記錄，\n"
             "徹底取代傷腑折壽之血精霸體催動法；後附八十七名陣亡重傷將士家鄉撫恤安置頁與\n"
             "「大伯燕山・黑冰斷谷失聯案備忘頁」。\n");
    set_weight(250);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
