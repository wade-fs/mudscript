// clone/item/residency_tally.c
// 金石黃木通牒 - 金石南關臨時入城信物 (72小時居留倒數)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("金石黃木通牒", ({ "residency tally", "tally", "residency_tally", "通牒", "黃木通牒", "木牌" }));
    set_short(YEL "【金石黃木通牒】" NOR);
    set_long("一面以劣質黃楊木削製的長條形入城腰牌，背面烙印著鮮紅的硃砂日晷印記。\n"
             "南關稅吏宋算子簽發此牌時標記了精確的入城時辰。持牌流民在城內僅享有七十二小時（三日）的合法逗留期，\n"
             "期限一過若無三大公會或官署的合法緩衝信物（青衿、藥囊、短褐），將被城防巡丁依律鎖拿投入死牢。\n");
    set_weight(100);
    set_value(20);
    set("is_residency_tally", 1);
}
