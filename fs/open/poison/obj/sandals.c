#include <ansi.h>
inherit EQUIP;

void create()
{ 
	set_name("木屐", ({"wood sandals", "sandals"} ));
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "雙");
		set("material", "wood");
		set("armor_prop/armor", 3);
		set("value",150);
		set("long","
一雙造型奇特的木製拖鞋，似是出自東洋工匠之手，非中原本土之物。\n");
		set("armor_type","boots");
		}
		setup();
}
