//blade.c : 大刀
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("鬼頭刀",({"ghost blade","blade"}));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把黑色烏鋼大刀 , 刀柄一個面目猙獰的鬼頭 , 甚為嚇人。\n");
		set("value",2000);
		set("material", "steel");
		set("wield_msg", "$N從腰間抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(40);
	setup();
}
