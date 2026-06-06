//whip.c

#include <weapon.h>

inherit STABBER;

int special_att();

void create()
{
	object me=this_player();
	set_name("丹青筆", ({"literate pen", "pen", "literate"}));
        set_weight(500);
	if( clonep() )
	 set_default_object(__FILE__);
	else 
	 {
	  set("unit", "支");
	  set("long","這是儒門專用的丹青筆﹐凡儒家有名之士都有。\n");
	  set("value", 1000);
	  set("material", "blacksteel");
	 }
	init_stabber(80);
	me->set("chat_chance_combat",10);
	setup();
}

