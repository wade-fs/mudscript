inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR + "朱雀羽冠" + NOR,({"rose finch's crest","crest"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火紅色的一頂羽冠，頭頂處有一個朱雀模型物。\n");
		set("unit","雙");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR + "$N戴上$n" + HIR + "，頭頂上的朱雀模型轉紅了。\n" + NOR);
		set("unequip_msg",HIR + "$N脫下了$n" + HIR + "，紅色的朱雀模型緩緩消逝了。\n" + NOR);
		set("armor_prop/force",5);
		set("armor_prop/armor",-20);
	        set("armor_type","head");
	}
	setup();
}
