// /clone/item/steady_copper_core.c
// 三枚無毒穩壓銅芯 (Ch.136, 138 償還衡真道人債務之跨極鍛件)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("穩壓銅芯", ({ "steady_copper_core", "copper core", "穩壓銅芯", "銅芯" }));
    set_short(YEL "萬物工會・三枚無毒穩壓銅芯" NOR);
    set_long("林鐵生藉齊九軸外環機床依標準公差鍛造的三枚紫銅穩壓內芯，\n"
             "專門用來抵補衡真道人於太虛校星觀測院的塔基檢修損耗。\n");
    set_weight(150);
    set_value(20);
    set("is_craft_part", 1);
}
