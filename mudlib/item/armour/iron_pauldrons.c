// item/armour/iron_pauldrons.c - 鐵製肩甲
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一對鐵製肩甲");
    set_long("這對肩甲由鍛打的鐵板製成，能有效保護肩膀和上臂，是戰士的常備裝備。\n");
    set_id(({"pauldrons", "iron pauldrons", "鐵肩甲", "肩甲"}));
    set_defence(4);
    set_slot(SLOT_SHOULDER);
    set_armour_class("medium");
    set_agility_pen(2);
    set_weight(1800);
    set_value(130);
}
