// make by Onion
#include <armor.h>
inherit EQUIP;

void create()
{
	set_name("藏青絲短袍", ({ "short robe", "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "這件衣服剪裁合適, 穿起來非常的合身。\n");
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor", 7);
	}
	setup();
}

