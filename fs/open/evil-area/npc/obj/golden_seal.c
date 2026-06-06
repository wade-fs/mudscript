inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY"黃金印"NOR,({"golden seal","seal"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
	set("value",10000);
	set("base_unit","顆");
	set("unit","盒");
	set("long",
"一個由黃金所雕碩成的印子。\n");
	}
	set_amount(1);
	setup();
}
