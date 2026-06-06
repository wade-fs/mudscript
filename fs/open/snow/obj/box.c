inherit ITEM;
#include <ansi.h>
#include "../../open.h"
void create()
{
     set_name(HIR + "獨孤愁的靈柩" + NOR,({"box"}));
     set("long","雪蒼派第三代掌門獨孤愁的靈柩﹐上面刻著「九轉邪雲」四個大字。\n");
     set("unit","俱");
     set_weight(1000000);
     set("value",10000);
     setup();
}
void init()
{
	add_action("do_search","search");
	add_action("do_push","push");
	add_action("do_enter","enter");
}
int do_search(string str)
{
	if(str!="box")
		return notify_fail("你在找什麼 ?\n");
tell_object(this_player(),"你發現在靈柩上的四個字﹐每個字都有一個類似暗門一類的東西﹐似乎可以壓(push)。\n");
	return 1;
}
int do_push(string str)
{
	if(str!="九"&&str!="轉"&&str!="邪"&&str!="雲")
		return notify_fail("你想推那裡 ?\n");
	if(str!="邪")
	{
	   message_vision(
		HIY + "$N觸碰了暗門﹐被一股強烈的力道反震﹐$N被彈了出去﹗\n"+HIR+"$N吐了口鮮血﹐受了極嚴重的內傷。\n" + NOR,this_player());
	   this_player()->add("kee",-100);
	   this_player()->move(SNOW_ROOM"ducu_room_in");
	   return 1;
	}
	tell_object(this_player(),"靈柩突然「喀」的一聲﹐打了開來﹐令人大吃一驚﹐裡面並沒有獨孤愁的遺體﹐只見一條密道(road)。\n");
	return 1;
}
int do_enter(string str)
{
	if(str!="road")
		return 0;
	tell_object(this_player(),"你慢慢地﹐一步一步走進密道。\n");
	this_player()->move("/open/snow/room/box_in");
	return 1;
}
