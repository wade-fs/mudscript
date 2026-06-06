
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("朴刀",({"pu blade","blade"}) );
	set_weight(4000);
	if ( clonep())
		set_default_object(__FILE__);
else 	{
	set("long","一把沉重但威力不錯的大刀，是強盜們慣用的兵器之一。\n");
	set("meterial","steel");
	set("value", 200);
	set("unit","把");
	set("wield_msg", "$N從腰間抽出一把明晃晃的大刀當武器。\n");
	set("unwield_msg","$N將刀收回腰中的刀鞘中。\n");
}
	init_blade(30);
	setup();
}


