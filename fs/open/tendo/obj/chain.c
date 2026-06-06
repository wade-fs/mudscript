// chain.c
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name(HIG "青龍崩雲鎖" NOR,({"dragon chain","chain"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
                set("value",30000);
		set("material","blacksteel");
		set("rigidity",60);
		set("long",
	"\n一條龍形的鎖鏈，相傳是天界鎖龍關的鎮關之物。\n");
	set("wield_msg", "$n感應到$N的智慧，一股龍氣自$N手中竄出。\n");
	set("unwield_msg","$n上的異光漸漸黯淡下來。\n");
	}
	init_whip(90);
	setup();
}




