inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居" + NOR);
	set("long",@LONG
一個由木板隔置於兩旁的通道，感覺上十分的狹窄漆黑，東西兩
旁通往大廳，往南通往後廂房。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"b-13",
"west":__DIR__"b-15",
"south":__DIR__"b-17",
]));
	setup();
}

 
