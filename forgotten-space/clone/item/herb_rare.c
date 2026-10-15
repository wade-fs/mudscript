// clone/item/herb_rare.c
// 百年鐵角七 - 唯有身負採藥天命者於絕壁偶得之珍稀老藥

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("鐵角七", ({ "rare herb", "iron herb", "tiejiaoqi", "鐵角七" }));
    set_short(HIY "百年鐵角七" NOR);
    set_long("生長於背陰絕壁陡峭石縫中的罕見古藥，狀如盤曲羚角，質地堅韌如鐵。\n"
             "歷經百年天地風霜洗禮，根鬚深扎黑石地脈，散發著濃郁辛辣的草木異香。\n"
             "服之能強健筋骨血脈，在府城黑市上亦是有價無市的珍品。\n");
    set_weight(300);
    set_value(200);
    set("herb_type", "rare");
}
