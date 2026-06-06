
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("人篸",({"ginseng"}) );
	set("base_weight", 50);
	set("unit","根");
	set("base_unit","根");
	set("value",1000);
	set_amount(1);
	set("long","
一根從深山中掘得的人篸，人篸對於人體健康有相當的幫助，是高級的補品
，但因其尋得不易，相對的價格亦高，尋常人家不是輕易買的起的。\n");
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
	int num=10+random(5);
	if ( !str || str!="ginseng") {return 0;}
	message_vision("$N吃下人篸，覺得精神恢復了不少。\n",me);
	this_player()->receive_heal("gin",num);
	add_amount(-1);
	return 1;
}

