// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("大刀", ({ "blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 800);
		set("material", "iron");
		set("long", "這是一柄沈重的大刀，刀柄綁著一條紅巾，使起來虎虎生風。\n");
		set("wield_msg", "$N抽出一柄明晃晃的$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(20);
	setup();
}
