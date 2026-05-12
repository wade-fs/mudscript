// item/armour/leather_belt.c - 皮製腰帶（腰部，微增防禦+攜帶量）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一條皮製腰帶");
    set_long("這條厚實的皮腰帶可以掛上小袋子，有幾個金屬鉤環，既實用又有型。\n");
    set_id(({"belt", "leather belt", "腰帶", "皮腰帶"}));
    set_defence(1);
    set_slot(SLOT_WAIST);
    set_armour_class("accessory");
    set_weight(200);
    set_value(30);
}
