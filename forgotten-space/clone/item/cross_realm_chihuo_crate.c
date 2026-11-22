// /clone/item/cross_realm_chihuo_crate.c
// 「赤火」跨界走私晶柱殘箱 (Ch.147 截獲赤煉／私盟暗道鐵證)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("赤火走私殘箱", ({ "cross_realm_chihuo_crate", "chihuo crate", "走私殘箱", "赤火殘箱" }));
    set_short(HIR "天工赤火印・跨界走私晶柱殘箱" NOR);
    set_long("從萬物主機城三號拆解線暗洞奪回的防潮鐵箱，箱角烙著清晰的凡間天工閣『赤火』篆印\n"
             "與近年雲津私盟交割編號，徹底坐實兩界高層之間存在偷運血精與延壽晶丹的走私暗道。\n");
    set_weight(350);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborated");
}
