
#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIR"紅花"NOR,({ "red flower", "flower" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
else	{
	set("meterial","leather");
	set("unit","朵");
	set("value", 0);
	set("armor_type","neck");
	set("armor_prop/armor", 1);
	set("long","
這是一朵鮮紅色的紅花，其特殊外形，不知有何特殊意義。\n");
	}
	setup();
}
