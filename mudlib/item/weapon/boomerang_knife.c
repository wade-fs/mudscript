// item/weapon/boomerang_knife.c - 回旋飛刀（投擲，自動回收）
#include "/include/config.h"
inherit "/std/weapon.c";
void create() {
    ::create();
    set_short("一把回旋飛刀");
    set_long("這把特製的飛刀刃口彎曲，投擲後會沿弧形軌道自動回到投擲者手中。\n");
    set_id(({"boomerang", "飛刀", "回旋飛刀"}));
    set_attack(10);
    set_weapon_type(WPN_DAGGER);
    set_damage_type("slash");
    set_range_type(RANGE_THROWN);
    set_range_distance(2);
    set_can_fly(2);
    set_weight(400);
    set_value(200);
}
