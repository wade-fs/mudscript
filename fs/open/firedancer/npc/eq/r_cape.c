inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀火篷"NOR,({"rose finch's cape","cape"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一條大斗篷，於斗篷中間處有朱雀的圖樣。\n");
		set("unit","條");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N披上$n"HIR"，斗篷上的朱雀圖樣轉紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀圖樣緩緩消逝了。\n"NOR);
		set("armor_prop/force",2);
		set("armor_prop/armor",-8);
	        set("armor_type","cape");
	}
	setup();
}
