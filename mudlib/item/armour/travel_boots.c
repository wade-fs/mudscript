// item/armour/travel_boots.c - 旅行靴（腳部）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一雙旅行靴");
    set_long("這雙靴子鞋底厚實，鞋幫高至腳踝，是長途跋涉的好選擇。\n");
    set_id(({"boots", "travel boots", "旅行靴", "靴子"}));
    set_defence(2);
    set_slot(SLOT_FEET);
    set_armour_class("light");
    set_weight(600);
    set_value(55);
}
