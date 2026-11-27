// clone/item/solvent_resin.c
// 化脂融膠散 - 杏林秘製生化溶解藥劑

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("化脂融膠散", ({ "solvent resin", "solvent", "rongjiaosan", "融膠散", "化脂融膠散" }));
    set_short(HIG "【化脂融膠散】" NOR);
    set_long("顧玄依據白草堂與孫先生毒理配方調配的強效化脂藥劑。\n"
             "散發微酸刺鼻的草木異香，遇水生濁油與高黏度水膠即產生微熱反應，\n"
             "能在十息之內將卡死水閘齒輪軸心的固化油脂與生化凝膠徹底瓦解融化。\n");
    set_weight(100);
    set_value(100);
    set("is_solvent", 1);
}
