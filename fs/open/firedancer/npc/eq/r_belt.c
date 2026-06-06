inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR + "朱雀束腰" + NOR,({"rose finch's belt","belt"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一條腰帶，於扣環處有朱雀浮雕的銅扣。\n");
		set("unit","條");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR + "$N套上$n" + HIR + "，扣環上的朱雀浮雕變紅了。\n" + NOR);
		set("unequip_msg",HIR + "$N解開了$n" + HIR + "，紅色的朱雀浮雕緩緩消逝了。\n" + NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","waist");
	}
	setup();
}
