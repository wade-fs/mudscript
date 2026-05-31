// golden_sword.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("巨靈斧", ({ "huge axe" }) );
    set_weight (20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("material", "gold");
	}
	init_axe(98);
	setup();
}
