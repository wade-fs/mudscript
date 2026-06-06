inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居" + NOR);
	set("long",@LONG
在你身旁擺放著一張石桌，石桌旁擺放著一些小石凳，石桌上擺
著一些素果與鮮花，給人一種樸素的親切感，很顯然的你可以猜測到
，這張石桌是用來進食用的。
東西兩旁各有一個通道，往北可通往大廳出入口。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-11",
"east":__DIR__"b-10",
"north":__DIR__"b-01",
]));
	setup();
}

 
