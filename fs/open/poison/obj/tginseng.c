
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("千年人篸",({"thousand ginseng","ginseng"}) );
	set("base_weight", 50);
	set("unit","根");
	set("base_unit","根");
	set("value",10000);
	set_amount(1);
	set("long","
千年人篸是人篸中的極品，在深山中埋藏千年吸收了千年的靈氣，因此在療效
上較普通人篸更好 , 相對的，其價格更是高的嚇人。\n");
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
	if ( !str || str!="ginseng") {return 0;}
	message_vision("$N將千年人篸服下，覺得精神似乎全恢復了。\n",me);
	this_player()->receive_heal("gin",num);
	add_amount(-1);
	return 1;
}

