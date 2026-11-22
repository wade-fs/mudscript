// /clone/item/guixu_threshold_record.c
// 《歸墟古淵門縫拓銘》(Ch.170)：第四卷結業與 Tier 4 門縫警示實錄（不自動解鎖 Tier 4）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    set_name("歸墟古淵門縫拓銘");
    set_short(HIC "歸墟古淵門縫拓銘" NOR);
    set_long("一塊拓印自碎石高原萬丈玄武岩裂隙口的冰冷石拓，上頭載有歸墟總閘門鬆動應力讀數，\n"
             "旁附三極重申之條例：凡欲涉足更深處【歸墟殘塚】，仍須獨立齊備地圖考據拼圖、三元共鳴窗口與心魔勘破。\n");
    set_id(({ "guixu_threshold_record", "threshold_record", "歸墟古淵門縫拓銘", "門縫拓銘" }));
    set("value", 250);
    set("weight", 4);
}
