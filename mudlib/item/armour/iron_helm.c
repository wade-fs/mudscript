// item/armour/iron_helm.c - 鐵盔（頭部）
#include "/include/config.h"
inherit "/std/armour.c";
void create() {
    ::create();
    set_short("一頂鐵盔");
    set_long("這是一頂樸素的鐵製頭盔，雖然沒有任何裝飾，但防護效果實用可靠。\n");
    set_id(({"helm", "iron helm", "鐵盔", "頭盔"}));
    set_defence(4);
    set_slot(SLOT_HEAD);
    set_armour_class("medium");
    set_weight(1500);
    set_value(100);
}
