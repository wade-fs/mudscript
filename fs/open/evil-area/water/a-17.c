inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
在你的正北方的湖面上，漂浮著一座建築物，你不斷的觀看著建
築物本身，可惜由於你身處於建築物背面不遠的南邊岸上，所以根本
無法看的到內部是長的如何，南邊傳來陣陣孩童的喧嘩聲～打亂了你
的思緒...
LONG);
	set("objects",([
__DIR__"npc/mob02":3,
]));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-18",
"east":__DIR__"a-16",
"south":__DIR__"a-30",
]));
	setup();
}

 
