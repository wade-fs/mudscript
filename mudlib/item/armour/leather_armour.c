// item/armour/leather_armour.c
#include "/include/config.h"
inherit "/std/armour.c";

void create() {
    ::create();
    set_short("一件皮革護甲");
    set_long("這是一件用粗獸皮縫製的護甲，能抵擋輕微的攻擊。\n");
    set_id(({"armour","leather","leather armour","皮甲","皮革護甲"}));
    set_defence(5);
    set_slot(SLOT_BODY);
    set_weight(2000);
    set_value(80);
}
