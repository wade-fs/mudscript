inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居" + NOR);
	set("long",@LONG
這是一大廳通往後廂房的一個轉角處，往西通往大廳，往南通往
後廂房。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-09",
"south":__DIR__"b-12",
]));
	setup();
}

 
