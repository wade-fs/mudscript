inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居 -- 後 院"NOR);
	set("long",@LONG
你正走在磚瓦鋪地的道路上，兩旁各式一個馬廄與大榕樹，往南
有一間木製的房屋，隱隱約約中，你可以聽到一些哀怨的哭泣聲，彷
彿是從木屋內傳出來的，往北則通往大廳內。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-24",
"enter":__DIR__"b-47",
]));
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "enter" )
	{
		if( !me->query_temp("evil/water/ask-mission-4") )
			return notify_fail("兩旁突然出現了兩位邪靈～

邪靈大聲喝道：你是誰～竟敢闖此地～活的不耐煩了嗎？\n");

		if( !present("evil-foods",me) )
			return notify_fail("兩旁突然出現了兩位邪靈～

邪靈大聲喝道：閒雜人等，不得進入～\n");

		message_vision("兩旁突然出現了兩位邪靈～

邪靈望了望$N，看著$N手中的食物說道：原來是送飯的...進去吧!!\n",me);
	}
	return 1;
}
 
