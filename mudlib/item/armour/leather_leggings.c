// item/armour/leather_leggings.c - 皮革護腿（腿部）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一件皮革護腿");
    set_long("這是用厚實獸皮縫製的護腿，延展性不錯，不會影響奔跑。\n");
    set_id(({"leggings", "leather leggings", "皮護腿", "護腿"}));
    set_defence(3);
    set_slot(SLOT_LEGS);
    set_armour_class("light");
    set_weight(1000);
    set_value(70);
}
