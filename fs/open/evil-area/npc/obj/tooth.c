inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR + "紅身狼牙" + NOR,({"red-wolf tooth","tooth"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
	set("value",100);
	set("base_unit","顆");
	set("unit","排");
	set("long",
"一隻紅色毛皮的狼，遺留下來的牙齒。\n");
	}
	set_amount(1);
	setup();
}
