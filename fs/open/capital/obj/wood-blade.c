// dagger.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("木刀",({"wood blade","blade"}) );
        set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("sharp",9);
		set("e-weapon",1);
                set("no_steal",1);
                set("no_give",1);
                set("no_get",1);
                set("no_auc",1);
		set("unit", "把");
                set("long","一把木製的刀子.\n");
                set("value", 100);
                set("material","crimsonsteel");
	}
        init_blade(5);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","$N右臂一振，一把木刀已經落在手上。\n");
        set("unwield_msg","$N將木刀往天空一拋，木刀自動回歸刀鞘。\n");

// The setup() is required.

	setup();
}
