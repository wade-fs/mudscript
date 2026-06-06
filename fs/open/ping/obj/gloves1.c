// by onion
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("白愁手套", ({ "white gloves", "gloves" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "上好白綢混著雪蠶絲製成的手套, 可抵擋一般兵器的攻擊。\n");
	  set("unit", "雙");
	  set("value", 2000);
	  set("material", "linen");
	  set("armor_type","hands");
	  set("armor_prop/armor", 5);
	}
	setup();
}

