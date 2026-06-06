// by onion
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("晨曦玉如意", ({ "morning jade", "jade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "入手溫涼的一塊玉如意, 上頭浮現著朵朵雲彩, 隱隱有晨曦剎現的樣子。\n");
	  set("unit", "塊");
          set("value", 1000);
          set("material", "gem");
	  set("armor_type","neck");
	  set("armor_prop/armor", 5);
	}
	setup();
}

