
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("鬼頭大刀",({"ghost glaive","glaive"}) );
	set_weight(12000);
	if ( clonep())
		set_default_object(__FILE__);
else 	{
	set("long","
一把極其沉重的大刀，沒有過人的臂力想必是舉不起來的，刀柄上還刻了一
個猙獰的鬼頭當裝飾。\n");
	set("meterial","steel");
	set("value", 500);
	set("unit","把");
	set("wield_msg", "$N從腰間抽出一把明晃晃的大刀當武器。\n");
	set("unwield_msg","$N將刀收回腰中的刀鞘中。\n");
}
	init_blade(40);
	setup();
}


