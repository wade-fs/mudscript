// by onion
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("金祿符", ({ "gold amulet", "amulet" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "這個符咒經過太上道人的施法, 具有避邪驅魔的法力, 符的四周還鑲著金邊。\n");
	  set("unit", "個");
          set("value", 600);
          set("material", "cloth");
	  set("armor_type","neck");
          set("armor_prop/armor", 3);
	}
	setup();
}

