// clone/item/steel_chisel.c
// 【百煉破煞玄鐵鋼鑿】 (小說第14章阿鐵親手淬鍊打造)

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("百煉破煞玄鐵鋼鑿");
    set_short(HIB "【百煉破煞玄鐵鋼鑿】" NOR);
    set_long("一柄兒臂粗細、沉重冰冷的重型開山鋼鑿。通體泛著幽黑青芒，由老鐵匠\n"
             "阿鐵引地爐千度炭火、經冷水急速淬火百煉而成，質地剛烈無匹，\n"
             "專克堅硬黑玄石與地下地煞岩層，可用於鑿擊石壁 (strike stone)。\n");
    set_id(({ "steel chisel", "chisel", "鋼鑿", "玄鐵鋼鑿", "破煞鋼鑿" }));

    set_weight(2500);
    set_value(300);
    set("is_chisel", 1);
    set("chisel_power", 50);
}
