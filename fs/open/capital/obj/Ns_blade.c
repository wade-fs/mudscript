// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("禁衛軍刀",({"soldier blade","blade"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","這是禁衛軍專用的刀。\n");
		set("value",600);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_blade(25);
	setup();
}
