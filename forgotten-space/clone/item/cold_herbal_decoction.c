// /clone/item/cold_herbal_decoction.c
// 野菊抗寒湯劑（第三卷 Ch.83 斷崖石棚驛站・抗寒救傷湯劑）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("野菊抗寒湯劑", ({ "cold_herbal_decoction", "herbal decoction", "decoction", "野菊抗寒湯劑", "抗寒湯劑" }));
    set_short(HIG "野菊抗寒湯劑" NOR);
    set_long("一只封著厚蠟的小陶瓶，裡頭裝著以葛半仙所贈金石野菊花、防瘴草籽配伍老薑\n"
             "文火慢煎而成的溫熱藥湯，散發著淡淡的辛香草氣，能有效緩解北境寒原早期凍傷與風寒失溫。\n");
    set_weight(120);
    set_value(180);
    set("is_consumable", 1);
}
