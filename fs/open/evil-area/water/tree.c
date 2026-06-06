#include <ansi.h>

void init()
{
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
	

int valid_leave(object me,string dir)
{
	if( dir == "up")
	{
		if( !me->query_temp("evil/water/climb") )
		{
			message_vision("$N努力的想爬上去，可是卻不小心的沒抓好樹幹～\n",me);
			call_out("move",1,me);
			return notify_fail(HIY + "你心想～不好了...:~...\n" + NOR);
		}
	message_vision("$N順利的爬了上去。\n",me);
	me->delete_temp("evil/water/climb");
	}
	return 1;
}

int move(object me)
{

	me->move("/open/evil-area/water/b-20");
	me->receive_wound("kee",500);
	COMBAT_D->report_status(me,1);
	message_vision(HIR + "\n$N重重的從樹上跌落於地～\n" + NOR);
}
