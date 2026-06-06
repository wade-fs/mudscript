inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀護套"NOR,({"rose finch's hands","hands"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一雙手套，於手背處畫有朱雀的圖樣。\n");
		set("unit","雙");
		set("value",2000);
		set("material","silver");
		set("wear_msg",HIR"$N套上$n"HIR"，手背上的朱雀圖樣轉紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀圖樣緩緩消逝了。\n"NOR);
		set("armor_prop/force",4);
		set("armor_prop/armor",-16);
	        set("armor_type","hands");
	}
	setup();
}
