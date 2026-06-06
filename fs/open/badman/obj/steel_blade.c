// steelblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("鋼刀", ({ "steel blade", "blade" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "steel");
		set("long", "這是一柄用精鋼煉製而成的刀，刀刃十分的鋒利。\n");
		set("wield_msg", "$N抽出一柄鋒利的$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(10);
	setup();
}
