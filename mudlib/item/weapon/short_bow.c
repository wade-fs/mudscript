// item/weapon/short_bow.c - 短弓（遠程，3格，需箭矢）
#include "/include/config.h"
inherit "/std/weapon.c";
void create() {
    ::create();
    set_short("一把短弓");
    set_long("這是一把用柔韌木材製成的短弓，拉力適中，適合初學者練習遠程射擊。\n");
    set_id(({"bow", "short bow", "短弓"}));
    set_attack(6);
    set_weapon_type(WPN_BOW);
    set_damage_type("pierce");
    set_two_handed(1);
    set_range_type(RANGE_RANGED);
    set_range_distance(3);
    set_can_fly(1);
    set_ammo_type(1);
    set_weight(800);
    set_value(120);
}
