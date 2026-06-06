inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨");
	set("long",@LONG
這裡放置著一張木桌與許多的椅子，看來是供蛇寨的守衛休息的
地方，西南邊有著一個石製的蛇雕，看起來栩栩如生。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier_1":2,
]));
	set("exits",([
"east":__DIR__"r-04",
"south":__DIR__"r-10",
]));
	setup();
}
