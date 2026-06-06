// dagger.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("彎月苗刀",({"maiu blade","blade"}) );
        set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","一把苗疆特製的大刀,成半月形.\n");
                set("value",1000);
		set("material", "steel");
	}
        init_blade(60);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","$N從背後抽出一把彎月苗刀.\n");
        set("unwield_msg","$N將彎月苗刀收入背後的刀鞘裡.\n");

// The setup() is required.

	setup();
}
