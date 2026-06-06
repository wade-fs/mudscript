// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("木劍",({"wood sword","sword"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","具有增強法力用的木劍。\n");
		set("material","wood");
	set("wield_msg","$N從背後拔出$n握在手中。\n");
		set("unwield_msg","$N將手中的$n掛回背後。\n");
	}
	init_sword(5);
	setup();
}
