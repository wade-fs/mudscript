
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("肉芝",({"ro mushroom","mushroom"}) );
	set("base_weight", 50);
	set("unit","朵");
	set("base_unit","朵");
	set("value",1000);
	set_amount(1);
	set("long","
肉芝是以動物屍骸為養份而生長的一種蕈類，在古中國，與石芝、木芝、
草芝、菌芝並稱五芝，是草藥中的特級品，彌足珍貴。\n");
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
	if ( !str || str != "mushroom") {return 0;}
	message_vision("$N服下靈芝，覺得恢復了不少元氣。\n",me);
	this_player()->receive_heal("sen",num);
	add_amount(-1);
	return 1;
}

