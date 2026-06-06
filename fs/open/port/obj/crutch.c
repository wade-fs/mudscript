// knife.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("柺杖",({"crutch"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",100);
		set("material","wood");
		set("long","由檜木所製成的柺杖 .\n");
		set("wield_msg","$N將$n拿在手中 .\n");
		set("unwield_msg", "$N將手中的$n收了起來 .\n");
	}
	init_staff(5);
	setup();
}
