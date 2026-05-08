// item/weapon/short_sword.c
#include "/include/config.h"
inherit "/std/weapon.c";

void create() {
    ::create();
    set_short("一把短劍");
    set_long("這是一把做工普通的鐵製短劍，刃口還算鋒利。\n");
    set_id(({"sword","short sword","短劍"}));
    set_attack(8);
    set_weapon_type(WPN_SWORD);
    set_damage_type("slash");
    set_weight(1000);
    set_value(50);
}
