#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("血龍果",({"blood fruit","fruit"}) );
	set("base_weight",50);
		set("unit","粒");	
		set("base_unit","粒");
		set("value",0);
		set_amount(1);
		set("long","一粒如血般紅的果子,相傳血龍果有療傷提神的效用。\n");
 	setup();
}
void init()
{
	if( this_player()==environment() )
	add_action("do_take","take");
}
int do_take(string arg)
{
	if( !arg || arg != "fruit") return notify_fail("你要吃甚麼呀?\n");
	message_vision(
"$N將血龍果一口吞下,只覺得渾身有說不出的暢快.\n",this_player() );

	this_player()->receive_heal("gin",10);
	this_player()->receive_heal("kee",10);
	this_player()->receive_heal("sen",10);
	this_player()->apply_condition("snake_poison", 0);
	add_amount(-1);
	return 1;
}
 
