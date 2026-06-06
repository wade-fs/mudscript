inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居 -- 後 院" + NOR);
	set("long",@LONG
你正走在磚瓦鋪地的道路上，兩旁各式一個馬廄與大榕樹，往南
有一間木製的房屋，隱隱約約中，你可以聽到一些哀怨的哭泣聲，彷
彿是從木屋內傳出來的，往北則通往大廳內。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-21",
"south":__DIR__"b-26",
"east":__DIR__"b-25",
"west":__DIR__"b-23",
]));
	setup();
}

 
