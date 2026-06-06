// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("武士金刀",({"gold blade","blade"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把極為鋒利的大刀 , 金光閃閃。\n");
		set("value",3500);
		set("material", "gold");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(45);

	set("ski_type1", "blade");
	set("ski_level1", 30);
	set("ski_type2", "gold-blade");
	set("ski_level2", 20);

	setup();
}
