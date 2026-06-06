inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIM"桃花源"NOR);
	set("long","
    一陣濃郁的花草香，瀰漫著整個房間，在房間的兩旁，放置著很
多瓦甕，裡面擺\滿了花花綠綠的花草，很多畸形百怪的形狀，房間的
正中央還擺\放一個較大的瓦甕，底下還有材火燃燒加熱，似乎在熬煮
某些藥草。
\n");
	set("exits",([
"west":__DIR__"c15",
"north":__DIR__"c11",
]));
	set("objects",([
__DIR__"npc/woman02":1,
]));
	setup();
}
