//black sword by urd for avatar
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("黑劍", ({"black sword","black","sword"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","把");
	set("long","這是聖者從美德試鍊場中收伏的惡魔所變成的劍，這是一把連\n英王都害怕
的劍。\n");
	set("material","crimsonsteel");
	set("value",5000000);
}
	init_sword(99);
	set("wield_msg","$N從身後取出$n來。\n");
	set("unwield_mag","$N把$n放到身後的劍綃中。\n");
	setup();
}

init wield()
{
	if ((string)this_player()->query("class") != "avatar")
		return notify_fail("$N不是聖者團的成員！！\n");
	else {
		::wield();
	}
	return 1;
}

