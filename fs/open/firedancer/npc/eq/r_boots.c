inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀雲靴"NOR,({"rose finch's boots","boots"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一雙軍靴，於靴子兩旁各有朱雀的圖樣。\n");
		set("unit","雙");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N穿上$n"HIR"，雲靴兩旁的朱雀圖樣泛紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀圖樣緩緩消逝了。\n"NOR);
		set("armor_prop/force",3);
		set("armor_prop/armor",-12);
	        set("armor_type","boots");
	}
	setup();
}
