// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
	set_name("白雲劍",({"un sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","仙劍七子之張乘雲的配劍\n");
		set("value",10000);
		set("material", "steel");
                set("wield_msg", "拿著$n,$N覺的渾身充滿了力量.\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_sword(60);
	setup();
}
