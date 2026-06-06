// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;
				
void create()
{
        set_name("虎頭鋼刀",({"steel blade","blade"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","這是把精鋼鑄成的長刀，刻了個虎頭做裝飾。\n");
		set("value",950);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_blade(40);
	setup();
}
