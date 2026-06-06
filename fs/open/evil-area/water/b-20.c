inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居 -- 後 院" + NOR);
	set("long",@LONG
高聳的天空，彷彿能藉著登上這棵大松樹而到達最頂端，這棵樹
可真所謂之高聳入雲霄，歲月的痕跡已經留在牠那斑駁而充滿樹洞的
身軀，如果想要爬(climb)上這棵大松樹，要先找立足點(find_hole)
，免得一個抓不穩，跌了個狗吃屎...那可真的划不來啊...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-19",
"south":__DIR__"b-23",
"east":__DIR__"b-21",
]));
	setup();
}

void init()
{
add_action("do_climb","climb");
add_action("do_find","find_hole");
}

int do_find()
{
object me = this_player();
int kar,str;

	kar = (int)me->query_kar();
	str = (int)me->query_str();

	me->delete_temp("evil/water/climb");

	if( kar < random(50) )
		return notify_fail("你不斷的尋找著踏腳點，可是週遭似乎找不到～\n");

	tell_object(me,"你左右巡視後，找到了一個踏腳點。\n");

	if( str < random(50) )
		return notify_fail("不過位置似乎有點遠，你評估你的力量，可能會無法施力而掉下去。\n");

	me->set_temp("evil/water/climb",1);
	tell_object(me,"你評估了一下，應該可以順利的爬上去。\n");
return 1;
}		
	

int do_climb()
{
object me;

	me = this_player();

	if( !me->query_temp("evil/water/climb") )
	{
		message_vision("$N努力的想爬上去，可是卻不小心的掉落於地～\n",me);
		me->receive_wound("kee",500);
		COMBAT_D->report_status(me,1);
		return notify_fail("你忍不住的心中暗喊疼～\n");
	}
	message_vision("$N順利的爬了上去。\n",me);
	me->delete_temp("evil/water/climb");
	me->move(__DIR__"b-28");
return 1;
}
