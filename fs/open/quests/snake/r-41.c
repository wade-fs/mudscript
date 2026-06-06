inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG

		～　開始有點亮光，不過依舊黑暗 ～

LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/poison_soldier":3,
]));
	set("exits",([
"north":__DIR__"r-42",
"south":__DIR__"r-30",
]));
	setup();
}
