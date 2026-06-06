inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀火盾"NOR,({"rose finch's shield","shield"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一片寶盾，盾中央處刻有朱雀的浮雕。\n");
		set("unit","片");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N拿起$n"HIR"，盾中央的朱雀浮雕轉紅了。\n"NOR);
		set("unequip_msg",HIR"$N放下了$n"HIR"，紅色的朱雀浮雕緩緩消逝了。\n"NOR);
		set("armor_prop/parry",5);
		set("armor_prop/armor",-20);
	        set("armor_type","shield");
	}
	setup();
}
