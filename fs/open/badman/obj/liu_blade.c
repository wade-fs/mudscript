// liu_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("柳葉刀", ({ "thin blade", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 800);
		set("material", "steel");
		set("long", "這是一柄十分細長的刀，平時可以藏在袖中，以發揮出絕佳的奇襲效果。\n");
		set("wield_msg", "$N暗暗的握緊了袖中的$n。\n");
		set("unwield_msg", "$N將手中的$n收回袖中。\n");
	}
	init_blade(40);
	setup();
}
