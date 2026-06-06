// by onion
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("勁雲靴", ({ "cloud boots", "boots" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "輕便且舒適的靴子, 兩旁各繡著一朵雲彩。\n");
	  set("unit", "雙");
	  set("value", 2000);
	  set("material", "linen");
          set("armor_prop/armor", 4);
	}
	setup();
}

