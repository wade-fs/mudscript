inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
花香輕飄撲鼻，你忍不住的發出讚嘆聲，實在很難想像，一個邪
靈將，荼炭生靈後，竟然會在邪靈界管理著這樣的一個地方，鳥語花
香，百物安寧，簡直不像是一個邪靈使所會做的一件事情，難不成，
情中有什麼隱情迫使著她嗎？
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-17",
"east":__DIR__"a-15",
]));
	setup();
}

 
