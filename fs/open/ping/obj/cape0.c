// make by Onion
#include <armor.h>
inherit CAPE;

void create()
{
	set_name("雲肩", ({ "cloud cape", "cape" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "棗紅色的雲肩披風, 有如落霞般的色彩斑斕。\n");
		set("unit", "件");
		set("value", 900);
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}

