#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "接天崖");
	set ("long", @LONG
矗立在你面前的是一大面的山壁，山壁上有各種不同的靈光緩緩
的從山頂上往下流落，面對這麼大一片山壁，似乎令人措手不及，不
知該如何往上爬(climb mountain)，這時正是你展現絕頂輕功的時候
了!!

LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);

	set("light_up", 1);

	setup();
}

void init()
{
	add_action ("do_climb","climb");
}

int do_climb (string str)
{
	object me;
	int i,j;
	me = this_player();
	i = me->query_skill("dodge",1);
	j = random(150);
	
	if( !str )
	return 0;

	if( str == "mountain" )
	{
	  if( i > j )
	  {
	  message_vision(HIY + "$N" + HIY + "馬不停蹄的展開絕世輕功\，依附著靈階繼續往山頂上爬去了。\n" + NOR, me);
	  me->move(__DIR__"sky02");
	  tell_room(environment(me),sprintf ("%s藉著上乘輕功\攀爬，終於氣喘噓噓漯忖F上來。\n", me->short()),me);
	  }else{
	  message_vision(HIR + "$N" + HIR + "腳下一個不小心，竟然從山壁上滾了下來，跌個鼻青臉腫的!!\n" + NOR,me);
	  me->start_busy(1);
	  }
	return 1;
	}else{
	return notify_fail("快快想清楚你要怎麼爬吧!!\n");
	}
}

