inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR + "朱雀肩章" + NOR,({"rose finch's armband","armband"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一張臂章，臂章上有朱雀的圖樣。\n");
		set("unit","張");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR + "$N勾上$n" + HIR + "，臂章上的朱雀圖樣轉紅了。\n" + NOR);
		set("unequip_msg",HIR + "$N卸下了$n" + HIR + "，紅色的朱雀圖樣緩緩消逝了。\n" + NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","armbands");
	}
	setup();
}
