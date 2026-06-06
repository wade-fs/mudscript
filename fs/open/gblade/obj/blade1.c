// dagger.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("鋒利大刀",({"large blade","blade"}) );
        set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","一把沾有血痕的大刀.\n");
                set("value",1000);
		set("material", "steel");
	}
        init_blade(30);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","$N從背後抽出一把可怕的大刀.\n");
        set("unwield_msg","$N將大刀收入背後的刀鞘裡.\n");
	set("ski_type1", "blade");
	set("ski_level1", 30);


// The setup() is required.

	setup();
}
