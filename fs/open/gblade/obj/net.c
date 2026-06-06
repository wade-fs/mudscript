// sword.c : an example weapon

#include <weapon.h>

 inherit STICK;

void create()
{
	set_name("捕蟲網",({"net"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把用來抓(cover)昆蟲的器具。\n");
		set("value",50);
		set("material", "wood");
		set("wield_msg", "$N 拿出一把$n放在手中。\n");
		set("unwield_msg", "$N將手中的$n收起來。\n");
	}
	init_stick(3);
	setup();
}
