inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨");
	set("long",@LONG
在你身旁佇立著一個蛇的石雕像，雕像上面似乎有刻著一些文字
，但似乎不是你所能理解的文字，東西兩旁擺放著許多的桌椅，看來
這裡似乎是大廳的休息室。
LONG);
	set("objects",([
__DIR__"npc/snake_soldier":2,
]));
	set("exits",([
"west":__DIR__"r-09",
"east":__DIR__"r-08",
"north":__DIR__"r-04",
"south":__DIR__"r-02",
]));
	setup();
}
