//whip.c
#include <ansi.h>
#include <weapon.h>

inherit STABBER;

int special_att();

void create()
{
	set_name(HIG "靈龍天筆" NOR,({"ten pen","pen"}));
	set_weight(1000);
	if( clonep() )
	 set_default_object(__FILE__);
	else 
	 {
	  set("unit", "支");
	set("long","這是儒門世代相傳的聖物﹐相傳是用千年玄鐵打造﹐無堅不摧。\n");
	  set("value", 10000);
	  set("material", "blacksteel");
          set("ski_level1", 35);
          set("ski_type1", "knowpen");
	 }
	init_stabber(80);
	setup();
}

