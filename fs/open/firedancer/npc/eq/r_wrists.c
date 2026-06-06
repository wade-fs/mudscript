inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀翌環"NOR,({"rose finch's bracelet","bracelet"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的手鐲，於接縫處刻有朱雀的鋼印。\n");
		set("unit","只");
		set("value",2000);
		set("material","steel");
		set("wear_msg",HIR"$N套上$n"HIR"，翌環上的朱雀鋼印變紅。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀鋼印緩緩消逝了。\n"NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","wrists");
	}
	setup();
}
