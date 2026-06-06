inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR + "朱雀火鍊" + NOR,({"rose finch's neck","neck"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一串項鍊，每一顆鍊珠都刻有朱雀的浮雕。\n");
		set("unit","片");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR + "$N帶上$n" + HIR + "，每顆珠子的朱雀浮雕轉紅了。\n" + NOR);
		set("unequip_msg",HIR + "$N拿下了$n" + HIR + "，紅色的朱雀浮雕緩緩消逝了。\n" + NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","neck");
	}
	setup();
}
