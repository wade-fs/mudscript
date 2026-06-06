inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀羅裙"NOR,({"rose finch's skirt","skirt"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一條羅裙，羅裙上畫有朱雀的浮雕。\n");
		set("unit","條");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N穿上$n"HIR"，羅裙上的朱雀浮雕轉紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀浮雕緩緩消逝了。\n"NOR);
		set("armor_prop/force",1);
		set("armor_prop/armor",-4);
	        set("armor_type","pants");
	}
	setup();
}
