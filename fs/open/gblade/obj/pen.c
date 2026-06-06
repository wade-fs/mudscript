//blade.c : 大刀

#include <weapon.h>

inherit STABBER;

void create()
{
	set_name("鐵筆",({"iron pen","pen"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long","以生鐵打造而成的筆 , 專供讀書人禦敵之用。\n");
		set("value",400);
	set("material","iron");
		set("wield_msg", "$N從懷裡拿出一隻$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n收進懷裡。\n");
	}
	init_stabber(12);
	setup();
}
