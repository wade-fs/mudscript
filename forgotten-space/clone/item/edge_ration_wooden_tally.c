// /clone/item/edge_ration_wooden_tally.c
// 灰燼石堡熱源配給牌 (Ch.127, 129, 134)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("灰燼石堡熱源配給牌", ({ "edge_ration_wooden_tally", "wooden tally", "tally", "配給牌", "熱源配給牌" }));
    set_short(YEL "灰燼石堡・焦黑熱源配給牌" NOR);
    set_long("一塊被窯火燻成焦褐色的硬木腰牌，正面烙著「守灰」二字與每日鹽晶、溫水配額刻痕，\n"
             "憑此牌方能在灰燼石堡地窯換取取暖餘溫與進出舊鹽道。\n");
    set_weight(60);
    set_value(0);
    set("is_credential", 1);
}
