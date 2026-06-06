//whip.c

#include <weapon.h>

inherit STABBER;

int special_att();

void create()
{
	object me=this_player();
	set_name("鑲銅筆", ({"Cu pen", "Cu", "pen"}));
        set_weight(2000);
	if( clonep() )
	 set_default_object(__FILE__);
	else 
	 {
	  set("unit", "支");
	  set("long","這是儒門書生們所用之筆﹐凡新進儒生都會擁有。\n");
	  set("value", 2500);
	  set("material", "iron");
	 }
     init_stabber(40);
	me->set("chat_chance_combat",10);
	setup();
}

