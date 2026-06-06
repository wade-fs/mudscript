inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀膝鎧"NOR,({"rose finch's leggings","leggings"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一套護膝，於護板上處有朱雀的雕刻。\n");
		set("unit","套");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N套上$n"HIR"，護板上的朱雀浮雕泛紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀浮雕緩緩消逝了。\n"NOR);
		set("armor_prop/force",3);
		set("armor_prop/armor",-12);
	        set("armor_type","leggings");
	}
	setup();
}
