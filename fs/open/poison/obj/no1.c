
inherit ITEM;
inherit "/open/poison/room/food.c";

void create()
{
	set_name("牛肉麵", ({"beef noodle","noodle"}) );
	set_weight(100);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一碗湯濃，肉又大塊的牛肉麵。\n");
		set("unit","碗");
		set("value",70);
		set("food_remaining", 5);
		set("food_supply", 100);
		set("eat_message","
$N喝了一口湯，吃了一口麵，並夾了一塊大大地牛肉放在口中咀嚼，真是一大享受。\n");
		}
	setup();
}

