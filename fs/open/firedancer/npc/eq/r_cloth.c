inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀羽衣"NOR,({"rose finch's cloth","cloth"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一件寶衣，於衣中央畫有朱雀的圖樣。\n");
		set("unit","雙");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N穿上$n"HIR"，衣上的朱雀圖樣轉紅了。\n"NOR);
		set("unequip_msg",HIR"$N脫下了$n"HIR"，紅色的朱雀圖樣緩緩消逝了。\n"NOR);
		set("armor_prop/force",5);
		set("armor_prop/armor",-20);
	        set("armor_type","cloth");
	}
	setup();
}
