inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖 旁"NOR);
	set("long",@LONG
琰揚湖旁的一個小空地，地上畫滿了很多的小圖形，感覺上似乎
是一處小孩子在遊樂玩耍的地方。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-17",
]));
	set("objects",([
__DIR__"npc/child":1,
]));
	setup();
}

 
