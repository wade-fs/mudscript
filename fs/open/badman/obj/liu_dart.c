// liu_dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("柳葉鏢", ({ "thin dart", "dart" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "枚");
		set("unit", "枚");
		set("value", 1800);
		set("material", "steel");
		set("long", "這是一枚十分細長的飛鏢，平時可以藏在袖中，以發揮出絕佳的奇襲效果。\n");
		set("wield_msg", "$N暗暗的握緊了袖中的$n。\n");
		set("unwield_msg", "$N將手中的$n收回袖中。\n");
	}
	init_throwing(60);
	set_amount(1);
	setup();
}
