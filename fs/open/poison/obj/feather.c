
#include <ansi.h>
inherit EQUIP;

void create()
{
    set_name(HIW + "鳳凰羽飾" + NOR,({"phoenix feather","feather"}) );
	set_weight(3000);
	if (clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
以鳳凰羽為飾天蠶絲織成的頭飾，似有靈力附著於上。\n");

		set("armor_type","head");
		set("material","blacksteel");
		set("unit","件");
		set("armor_prop/armor",9);
		set("value",450);
		set("armor_prop/magic",2);
       set("armor_prop/whip",2);
		setup();
	}
}
