// clone/item/steel_grinder.c
// 百煉雙耳鋼碾 - 五位少年協同鍛打的重型藥碾，能抗萬度地煞毒火 (小說第7章)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("百煉雙耳鋼碾", ({ "steel grinder", "grinder", "鋼碾", "藥碾", "雙耳鋼碾" }));
    set_short(HIW "百煉雙耳鋼碾" NOR);
    set_long("一具由五位底層少年在鐵匠鋪地火前合力鍛打而成的重型精鋼藥碾。\n"
             "重達三百斤，碾身線條剛勁古拙，碾槽平滑如鏡，隱隱泛著一層青玉般的天然\n"
             "淬火暗紋。槽壁內刻有辟火神紋，能承受極致陰陽地煞的研磨而不裂。(不可移動)\n");
    set_weight(150000);
    set_value(5000);
    set("no_get", 1);
}
