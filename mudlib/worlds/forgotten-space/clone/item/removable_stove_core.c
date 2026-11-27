// /clone/item/removable_stove_core.c
// 可拆卸換芯暖爐 (Ch.132 守人匠道實作)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("可拆卸換芯暖爐", ({ "removable_stove_core", "stove core", "暖爐", "換芯暖爐", "可拆卸換芯暖爐" }));
    set_short(HIR "熟鐵活榫・可拆卸換芯暖爐" NOR);
    set_long("林鐵生以精鋼分寸卡尺對照公差、用粗熟鐵與熟銅箔改製而成的輕便地窯暖爐。\n"
             "底座採雙向活榫插銷設計，燒鈍結渣後只需拔銷清灰、添入一撮粗鹽晶粉即可續燒三日。\n");
    set_weight(450);
    set_value(50);
    set("is_craft_prototype", 1);
}
