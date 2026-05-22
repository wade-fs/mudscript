// /item/armour/reinforced_shield.c
#include "/include/config.h"
inherit "/std/armour";

void create() {
    ::create();
    set_name("加固木盾");
    set_short("一面加固過的木盾");
    set_long("這是一面原本普通的木盾，表面覆蓋了一層堅硬的螃蟹殼，防禦力大幅提升。\n");
    set_id(({"shield", "wood shield", "木盾", "盾"}));
    set_slot(SLOT_SHIELD);
    set_defence(12);
    set_weight(1500);
}
