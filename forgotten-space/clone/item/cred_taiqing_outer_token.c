// /clone/item/cred_taiqing_outer_token.c
// 太清玄天宮外門玉牌（第三卷 Ch.86 登天雲梯通過憑證）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太清外門玉牌", ({ "cred_taiqing_outer_token", "taiqing token", "太清外門玉牌", "外門玉牌" }));
    set_short(HIC "太清玄天宮・周天星律外門玉牌" NOR);
    set_long("一枚觸手清涼的青玉令牌，正面陰刻太清雲紋，背面銘著「周天星律院外門上等經生」\n"
             "字樣。此牌僅限通行外門雲舍與星律院課業，未經掌院批令不得擅入藏星秘閣。\n");
    set_weight(50);
    set_value(0);
    set("is_credential", 1);
    set("sect", "taiqing");
}
