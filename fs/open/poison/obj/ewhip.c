#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
	set_name("冥蠱長鞭", ({"evil whip","whip"}));
	set_weight(500);

	if( clonep() )
             set_default_object(__FILE__);
else

{
	set("material","steel");
	set("value",300);
set("long","這是一把冥蠱教徒貫用的鞭子。\n");

	set("wield_msg", "$N將鞭子緩緩的從腰間解下，握在手上。\n");
	set("unwield_msg","$N將鞭子放下，纏在腰上。\n");
	set("unit", "把");
}
	init_whip(8);
	setup();
}

