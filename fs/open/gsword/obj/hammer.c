// sword.c : an example weapon

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("鐵鎚", ({"hammer" }));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把生鏽的鐵鎚 .\n");
		set("value", 230);
		set("material", "iron");
	}
        init_hammer(10);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N 拿出一把$n,稱了稱重量 ,握在手中 。\n");
	set("unwield_msg", "$N將手中的$n收入懷中。\n");

// The setup() is required.

	setup();
}
