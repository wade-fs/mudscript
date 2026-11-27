// /clone/item/cred_tiangong_artisan_tag.c
// 天工閣外門匠牌（第三卷 Ch.88 千鍛地火廊通過憑證）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("天工閣外門匠牌", ({ "cred_tiangong_artisan_tag", "tiangong tag", "天工閣外門匠牌", "外門匠牌" }));
    set_short(HIY "千機百巧門・天工閣外門匠牌" NOR);
    set_long("一枚以高純度青銅合金精鑄而成的齒輪狀匠牌，邊角刻有千機院核驗紋路。\n"
             "持有此牌可入地火鍛兵台領用基礎精鐵與礦煤材料，惟高危萬機地窟仍須雙人批令。\n");
    set_weight(80);
    set_value(0);
    set("is_credential", 1);
    set("sect", "tiangong");
}
