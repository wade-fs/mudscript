// knife.c

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("釣竿",({"fishing rod","rod"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",100);
		set("material","wood");
		set("long","一把木制的釣竿 , 似乎可以當作武器來用 .\n");
		set("wield_msg","$N將$n拿在手中 .\n");
		set("unwield_msg", "$N將手中的$n收了起來 .\n");
	}
	init_stick(5);
	setup();
}
