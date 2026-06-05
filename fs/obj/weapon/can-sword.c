// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIC + "干將之劍" + NOR,({"can sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",30000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_sword(80);
	setup();
}
