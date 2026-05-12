// item/armour/leather_gloves.c - 皮手套（手部）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一副皮手套");
    set_long("這副皮手套指節處略有加厚，戴上後握劍更穩，也能保護手背。\n");
    set_id(({"gloves", "leather gloves", "皮手套", "手套"}));
    set_defence(2);
    set_slot(SLOT_HANDS);
    set_armour_class("light");
    set_weight(300);
    set_value(40);
}
