inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨 置物室");
	set("long",@LONG
這是一個半大不小的密閉空間，你可以看到西北方有一個蛇型的
座椅，不過如果說是蛇寨寨主的王座，似乎又顯得有點小氣，週遭擺
滿了許多的黃金與珠寶，看來這裡是放置寶物的地方。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/snake_soldier":1,
"/obj/money/gold":5,
]));
	set("exits",([
"west":__DIR__"r-05",
"north":__DIR__"r-18",
]));
	setup();
}
