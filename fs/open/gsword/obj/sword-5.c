// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
   set_name("梅影劍", ({"may sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","仙劍七子中女劍俠梅影的寶劍，劍身通體呈白色\n");
		set("value",10000);
		set("material", "steel");
                set("wield_msg", "拿著$n,$N覺的渾身充滿了力量.\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_sword(60);
	setup();
}
