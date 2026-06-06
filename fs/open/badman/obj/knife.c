// knife.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("小刀", ({ "knife" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 250);
		set("material", "iron");
		set("long", "一把鋒利的小刀，適合近身搏鬥時使用。\n");
		set("wield_msg", "$N將$n倒握在手中。\n");
		set("unwield_msg", "$N將手中的$n放入口袋中。\n");
	}
	init_blade(5, SECONDARY);
	setup();
}
