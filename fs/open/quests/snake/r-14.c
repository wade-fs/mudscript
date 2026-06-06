inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨 二層");
	set("long",@LONG
石製的蛇寨顯得十分的堅固，你正位於蛇寨前棟，東西兩旁，各
自放置著一張木桌與許多的椅子，看來這層是供蛇寨的守衛休息的地
方。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier_1":3,
]));
	set("exits",([
"west":__DIR__"r-13",
"east":__DIR__"r-15",
]));
	setup();
}
