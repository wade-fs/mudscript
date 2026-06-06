//blade.c : 大刀
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("山寨鐵製大刀",({"guard blade","blade"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","一把由山寨守衛自己打造的鐵製大刀。\n");
		set("value",1000);
		set("material", "steel");
		set("wield_msg", "$N從腰間抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(28);
	setup();
}
