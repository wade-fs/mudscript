// by onion
#include <armor.h>
inherit EQUIP;
void create()
{
	set_name("手鏈", ({ "chainlet" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "精細的一條小鍊子, 可以結在雙手的腕上。\n");
	  set("unit", "條");
	  set("value", 300);
	  set("material", "iron");
	  set("armor_type","wrists");
	  set("armor_prop/armor", 2);
	}
	setup();
}

