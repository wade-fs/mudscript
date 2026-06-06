// manque_shield.c		designed by dos 95'12

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("失意盾", ({ "manque shield", "shield"}));
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", "這是失意劍客的盾, 盾面已經磨糊不清了, 
但是看起來還是十分監固的樣子. \n");
		set("value", 2000);
		set("material", "gold");
		set("armor_prop/armor", 15);
		set("armor_prop/dodge", -5);
	}
//  	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wear_msg", "$N把$n拿了出來, 放在胸前. \n");
	set("remove_msg", "$N把$n收了起來. \n");

// The setup() is required.

	setup();
}
