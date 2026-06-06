// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;
				
void create()
{
	set_name("虎頭軍刀",({"tiger blade","blade"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","由精鋼鑄成 , 非常鋒利 , 是守衛隊頭的裝備 .\,
 刀身染滿了倭寇的鮮血 .\n");
		set("value",10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		 set("unwield_msg", "$N將手中的$n收了起來 .\n");
	}
	init_blade(60);
	setup();
}
