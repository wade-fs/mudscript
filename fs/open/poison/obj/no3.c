
inherit ITEM;
inherit "/open/poison/room/food.c";

void create()
{
	set_name("鍋燒意麵", ({"guo-sau noodle","noodle"}) );
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","
一碗很不尋常的麵，麵裡有蛋、海鮮、肉類，味道相當鮮美。\n");
		set("unit","碗");
		set("value", 50);
		set("food_remaining",5);
		set("food_supply",70);
	}
	setup();
}

