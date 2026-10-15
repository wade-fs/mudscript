// clone/item/herb_common.c
// 新鮮草藥 - 黑石鋪南谷水邊野生草藥

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("草藥", ({ "herb", "fresh herb", "caoyao", "草藥" }));
    set_short("新鮮草藥");
    set_long("一株剛從溪谷潮濕石縫中掘出的野生草藥，莖葉青綠，散發著微苦的草木清香。\n"
             "可用於簡易敷傷止血，亦可賣予郎中或商隊換取銅幣。\n");
    set_weight(200);
    set_value(15);
    set("herb_type", "common");
}
