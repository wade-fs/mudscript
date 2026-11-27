// /clone/item/cred_bahuang_camp_plate.c
// 八荒黑山營腰牌（第三卷 Ch.87 萬鈞問心谷通過憑證）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("八荒黑山營腰牌", ({ "cred_bahuang_camp_plate", "bahuang plate", "八荒黑山營腰牌", "黑山營腰牌" }));
    set_short(HIR "八荒武山・黑山煞血營腰牌" NOR);
    set_long("一塊以生鐵冷鍛而成的厚重黑鐵腰牌，邊緣留有磨砂防滑齒紋，正面烙著八荒雙刃\n"
             "開山斧徽記，憑此牌可於黑山煞血營點卯領取冬甲、箭械與例行巡防補給。\n");
    set_weight(120);
    set_value(0);
    set("is_credential", 1);
    set("sect", "bahuang");
}
