// item/weapon/lightning_staff.c - 閃電法杖（魔法，元素：lightning）
#include "/include/config.h"
inherit "/std/weapon.c";
void create() {
    ::create();
    set_short("一根閃電法杖");
    set_long("這根法杖頂端鑲嵌著藍色晶石，空氣中瀰漫著輕微的靜電，靠近時頭髮都會豎起來。\n");
    set_id(({"lightning staff", "閃電法杖", "法杖", "staff"}));
    set_attack(14);
    set_weapon_type(WPN_STAFF);
    set_damage_type("magic");
    set_two_handed(1);
    set_range_type(RANGE_MAGIC);
    set_range_distance(4);
    set_can_fly(0);
    set_magic_level(3);
    set_element("lightning");
    set_weight(1200);
    set_value(500);
}
