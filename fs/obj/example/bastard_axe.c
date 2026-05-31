// bastard_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("重型破壞之斧", ({ "bastard axe", "axe" }) );
	set_weight(37000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把極其沈重的戰斧。\n");
		set("value", 7400);
		set("material", "steel");
	}
	init_axe(65);

// These properties are optional, if you don't set them, it will use the
// default values.

	setup();
}
