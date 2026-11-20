// /clone/item/pill_reverse_dao_life.c
// 逆道延命血丹殘樣暨丙柒門縫爐灰蠟管（第三卷 Ch.96 地肺丹火窟）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("逆道延命血丹殘樣", ({ "pill_reverse_dao_life", "reverse dao pill", "blood pill sample", "逆道延命血丹殘樣", "血丹殘樣" }));
    set_short(HIR "丙柒爐灰與血丹殘樣蠟管" NOR);
    set_long("以小銀勺自地肺丹火窟「丙字柒號」玄鐵門縫刮取的指甲蓋大暗紫色殘灰，封入雙層蠟管。\n"
             "殘灰混有金石府「丙字柒號紫銅坩堝」熔煉氣息、水銀雜質及三階冰原荒獸血渣；附頁草紙記著\n"
             "鐵箱上的紅漆雙重交割編號「萬山乙零四・南十三」與「烈礬耐火白泥」封口樣式。\n");
    set_weight(60);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "lead_only");
}
