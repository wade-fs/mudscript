inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
往西邊望去，似乎有一座建築物在那，北邊的路已經被沙丘給擋
住而無法通行。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"a-06",
"west":__DIR__"a-04",
]));
	setup();
}

 
