// /clone/item/ev3_drill_head.c
// 天工閣內造鑽山傀儡鑽頭殘件（第三卷 Ch.109 方舟東側冷卻豁口）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("鑽山傀儡鑽頭殘件", ({ "ev3_drill_head", "drill_head", "drill", "鑽山傀儡鑽頭殘件", "鑽頭殘件" }));
    set_short(HIR "天工閣內造・鑽山傀儡鑽頭殘件" NOR);
    set_long("總閘門鎖死七成流量、液壓倒灌炸毀前排五具鑽山傀儡後現場撿獲的兩截合金鑽頭碎片。\n"
             "金屬截面還粘附著暗紅血精凝膠，鋼樑外緣清楚打著天工閣內造出廠批號與四名獲救工役\n"
             "按押的指印封條——實證天工閣重型工程器械被調用於強鑿北荒方舟冷卻外殼。\n");
    set_weight(650);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
