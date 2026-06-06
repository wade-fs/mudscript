inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR + "(毀壞的)燃木材" + NOR,({"bad torch","torch"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
	else
	{
		set("value",10);
		set("base_unit","根");
		set("unit","堆");
		set("long","這是一根已經燃燒過的木材，無法再度燃燒。\n");
	}
	set_amount(1);
setup();
}
