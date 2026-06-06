inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居" + NOR);
	set("long",@LONG
一個由木板隔置於兩旁的通道，感覺上十分的狹窄漆黑，往北通
往大廳，往東通往後廂房。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-16",
"east":__DIR__"b-14",
]));
	setup();
}

 
