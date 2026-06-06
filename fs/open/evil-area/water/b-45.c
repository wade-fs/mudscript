inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIG + "琰 揚 居 -- " + NOR+YEL + "大 松 樹" + NOR);
	set("long",@LONG
你有點不敢相信自己的眼睛，這麼大的一隻蜜蜂，或許就你所知
的，牠是應該叫做蜜蜂吧，你可以清楚的看到這些你所謂的蜜蜂正在
此棵樹的最頂端進進出出自己的蜂巢，一但你有想繼續往上爬的動作
，牠們就彷彿在警告你的不斷震動翅膀，看來如果不驅走目前在你身
旁圍繞的〔蜜蜂〕，你是無法繼續往上爬。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"b-46",
"down":__DIR__"b-44",
]));
	setup();
}

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
		if( !present("chu-wood",me) )
		{
			message_vision("$N抓住樹幹，準備衝向樹頂時，一群蜜蜂突然飛繞在你身旁～\n",me);
			call_out("move",1,me);
			return notify_fail(HIY + "你心想～不好了...:~...\n" + NOR);
		}
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
