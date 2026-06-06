inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
對於你正東方有一個建築物正漂浮於水面上，吸引了你的視線，
你邊走邊望向湖泊上的建築物，一不小心你就撞到了正旁行在地上的
邪獸～儘管你不斷的道歉，邪獸似乎完全聽不懂你在說什麼，顧自的
繼續爬行，面對這種窘況，你也只好笑了笑，繼續的走著。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/mob01":1,
__DIR__"npc/mob02":1,
__DIR__"npc/mob03":1,
]));
	set("exits",([
"north":__DIR__"a-21",
"south":__DIR__"a-19",
]));
	setup();
}

 
