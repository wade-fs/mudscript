#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "天靈第二階");
	set ("long", @LONG
抬頭向上望，離目標還有一大段的距離，你只能再接再厲的往上
爬了，但天靈階卻不是那麼容易爬的，仍需小心，否則會摔落到山崖
下方的。

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
	j = random(130);
	
	if( !str )
	return 0;

	if( str == "mountain" )
	{
	  if( i > j )
	  {
	  message_vision(HIY"$N"HIY"馬不停蹄的展開絕世輕功\，依附著靈階繼續往山頂上爬去了。\n"NOR, me);
	  me->move(__DIR__"sky04");
	  tell_room(environment(me),sprintf ("%s藉著上乘輕功\攀爬，終於氣喘噓噓漯忖F上來。\n", me->short()),me);
	  }else{
	  message_vision(HIR"$N"HIR"腳下一個不小心，竟然從山壁上滾了下來，跌個鼻青臉腫的!!\n"NOR,me);
	  me->move(__DIR__"sky02");
	  me->start_busy(1);
	  }
	return 1;
	}else{
	return notify_fail("快快想清楚你要怎麼爬吧!!\n");
	}

}
