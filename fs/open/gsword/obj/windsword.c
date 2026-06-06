// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("旋風之劍",({ "windsword","sword" }) );
        set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","這就是大將軍 左正心愛的寶劍,將軍常帶著它去東征北討.\n");
                set("value", 1000);
		set("material", "steel");
	}
        init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","只見一股陰風襲來,在$N手中聚成一把利劍.\n");
        set("unwield_msg","$N手中一放,旋風劍化做清風消逝.\n");

// The setup() is required.

	setup();
}
