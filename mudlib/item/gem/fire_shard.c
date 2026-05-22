// /item/gem/fire_shard.c
#include "/include/ansi.h"
inherit "/std/item";

void create() {
    ::create();
    set_name("火焰碎石");
    set_short(HIR("火紅色的碎石"));
    set_long("一顆散發著熱氣的紅色碎石，內部流動著微弱的能量。\n");
    set_id(({"fire shard", "shard", "碎石", "火焰碎石"}));
    set_item_type("gem");
    set_value(100);
}
