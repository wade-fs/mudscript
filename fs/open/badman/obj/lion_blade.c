// lion_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("獅王戰刀", ({ "lion blade", "blade" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 4000);
		set("material", "steel");
		set("long", "這是一柄巨大的戰刀，刀身足足有三尺長，重逾百斤，一般人恐怕難以使得動。\n");
		set("wield_msg", "$N雙手握住背上的刀柄，真氣一提將$n抽了出來握在手中。\n");
		set("unwield_msg", "$N將手中的$n插回背後的刀鞘中。\n");
	}
	init_blade(70, TWO_HANDED);
	setup();
}
