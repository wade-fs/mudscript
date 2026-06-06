inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨");
	set( "build", 12 );
	set("long",@LONG
蛇寨是由石頭所組製而成的，在你的東西兩旁，各有一個向上的
通道，正北方，也有一個石製的蛇型像，看起來十分的逼真，在蛇型
像的背後似乎也有著一到門...
LONG);
	set("objects",([
__DIR__"npc/snake_soldier":2,
]));
	set("exits",([
"out":__DIR__"r-01",
"west":__DIR__"r-07",
"east":__DIR__"r-06",
"north":__DIR__"r-03",
]));
	setup();
}
