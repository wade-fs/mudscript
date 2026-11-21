// /clone/item/detachable_feedback_spec.c
// 《三段式可拆卸機械力回授連動台圖紙》（第三卷 Ch.121：林鐵生拒接神識、格物守人之工程定案）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("可拆卸連動台圖紙", ({ "detachable_feedback_spec", "feedback_spec", "連動台圖紙", "回授圖紙" }));
    set_short(HIY "林鐵生手繪・《三段式可拆卸機械力回授連動台圖紙》" NOR);
    set_long("林鐵生拒絶太清暨千機總監察使令以本命神識接入巨靈神機核心導線後，於萬機地窟\n"
             "燈下連繪半月而成之純機械改裝總圖。以按太古不融黑鐵微米弧度翻砂之複合合金副軸，\n"
             "配左腕壓力油管回饋與雙組機械緩衝彈簧踏板，並保留三個可隨時拔掉卡榫輪換之標準席位，\n"
             "在不用一克血精、不綁死任何一條人魂的情況下，令十丈神機誤差不超半厘平穩行禮。\n");
    set_weight(220);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "conclusive");
}
