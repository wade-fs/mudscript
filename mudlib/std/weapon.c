// std/weapon.c - 武器基底類別

#include "/include/config.h"

inherit "/std/item.c";
inherit "/std/interactive.c";

int    attack_bonus;  // 攻擊力加成
string weapon_type;   // WPN_SWORD / WPN_AXE ...
int    two_handed;    // 是否雙手武器
string damage_type;   // "slash" / "pierce" / "blunt" / "magic"

void create() {
    ::create();
    set_item_type(ITEM_WEAPON);
    attack_bonus = 5;
    weapon_type  = WPN_SWORD;
    two_handed   = 0;
    damage_type  = "slash";
}

void set_attack(int v)         { attack_bonus = v; }
void set_weapon_type(string t) { weapon_type  = t; }
void set_two_handed(int v)     { two_handed   = v; }
void set_damage_type(string t) { damage_type  = t; }

int    query_attack()      { return attack_bonus; }
string query_slot()        { return SLOT_WEAPON; }
string query_weapon_type() { return weapon_type; }
int    query_two_handed()  { return two_handed; }
string query_damage_type() { return damage_type; }
