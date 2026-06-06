// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;
				
void create()
{
	set_name("狼牙軍刀",({"wolf blade","blade"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","上等精鋼煉製而成 , 一直是守衛隊副隊頭最得力的助手 .\n");
	set("value",3000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		 set("unwield_msg", "$N將手中的$n收了起來 .\n");
	}
	init_blade(40);
	setup();
}
