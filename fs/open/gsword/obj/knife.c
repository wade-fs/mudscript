// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("烏鋼菜刀",({"steel knife","knife"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","仙劍廚子 --- 王安專用菜刀 。\n");
		set("value",600);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的刀鞘 。\n");
	}
	init_blade(27);
	setup();
}
