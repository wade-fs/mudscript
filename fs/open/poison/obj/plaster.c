
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("金創藥",({"plaster"}) );
	set("long","
最尋常的刀傷藥，你可以將它敷在傷口上(dress)。\n");
	set("value",150);
	set("base_weight",50);
	set("base_unit","盒");
	set("unit","盒");
	set_amount(1);
	setup();
}
void init()
{
	add_action("do_dress","dress");
}
int do_dress(string str)
{
	object me=this_player();
	int num=15+random(5);
	if(!str ||str!="plaster") 
	return notify_fail("你想敷甚麼呀!\n");
	message_vision("$N將金創藥敷在傷口上，傷勢漸漸好轉。\n",me);
	this_player()->receive_curing("kee",num);
	add_amount(-1);

	return 1;
}
