
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("千年靈芝",({"thousand mushroom","mushroom"}) );

	set("base_weight", 50);
	set("unit","朵");
	set("base_unit","朵");
	set("value",10000);
	set_amount(1);
	set("long","
在深山中生長千年的靈芝，和千年人篸一般吸收了千年的靈氣，在補品中亦
同樣屬於特極品，傳說靈芝生長過萬年甚至能化成人形，具思想，能走動，
但亦屬傳說，無法證實。\n");
	setup();
}
void init()
{
	if ( this_player()==environment() )
	add_action("do_eat","eat");
}
int do_eat(string str)
{	
	object me=this_player();
	int num=100+random(10);
	if ( !str || str != "mushroom") {return 0;}
	message_vision("$N吃下千年靈芝，覺得全身的元氣似乎都恢復了。\n",me);
	this_player()->receive_heal("sen",num);
	add_amount(-1);
	return 1;
}

