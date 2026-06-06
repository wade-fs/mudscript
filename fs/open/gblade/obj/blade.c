//blade.c : 大刀

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("單刀",({"blade"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把鐵製單刀 , 是行走江湖不可或缺之物。\n");
		set("value",400);
		set("material", "steel");
		set("wield_msg", "$N從腰間抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(15);

	setup();
}
