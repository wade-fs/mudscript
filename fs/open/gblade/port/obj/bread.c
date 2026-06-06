// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("波蘿麵包",({"bread"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","又香又白的大麵包 , 真想一口把他吞了 !\n");
		set("unit", "個");
		set("value",50);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
	setup();
}
