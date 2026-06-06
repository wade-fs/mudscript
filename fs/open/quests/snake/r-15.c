inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨 二層");
	set("long",@LONG
石製的蛇寨顯得十分的堅固，你正位於蛇寨前棟的東南角，東西
兩旁，各放置著一張木桌與許多的椅子，看來這層是供蛇寨的守衛休
息的地方。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier":1,
]));
	set("exits",([
"west":__DIR__"r-14",
"east":__DIR__"r-16",
"down":__DIR__"r-06",
]));
	setup();
}
