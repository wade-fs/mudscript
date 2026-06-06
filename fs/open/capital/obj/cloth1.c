// make by Onion
#include <armor.h>
inherit EQUIP;

void create()
{
	set_name("夜行衣", ({ "night cloth", "cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "夜間行動最適合的衣服, 幾與黑夜混為一體。\n");
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor", 5);
	}
	setup();
}

