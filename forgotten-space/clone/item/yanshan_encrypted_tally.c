// /clone/item/yanshan_encrypted_tally.c
// 燕山五年加密殘牌 (Ch.151, 160 FS-03 交叉比對證物)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("燕山加密殘牌", ({ "yanshan_encrypted_tally", "yanshan tally", "加密殘牌", "燕山殘牌" }));
    set_short(YEL "焦黑邊角・燕山五年加密殘牌" NOR);
    set_long("獨眼大伯燕山貼身暗藏五年的半塊軍需鐵牌，背面刻著雲津古篆與金石軍需副聯接應暗號，\n"
             "可直接與凡間雷烈留存之卷宗交叉鎖定五年前黑冰斷谷的真正簽署黑手。\n");
    set_weight(50);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborated");
}
