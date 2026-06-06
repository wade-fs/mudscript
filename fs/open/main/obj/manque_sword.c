//	manque_sword.c		designed by dos	 95'12

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("失意劍", ({ "manque sword","sword"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是失意劍客的劍, 劍端有時候會滴著水,
就好像是流眼淚\似的. \n");
		set("value", 1500);
		set("material", "gold");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N唰的一聲, 把劍抽了出來, 緊緊的握在手中. \n");
	set("unwield_msg", "$N把握在手上的$n緩緩的差入劍鞘. \n");

// The setup() is required.

	setup();
}
