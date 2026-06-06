inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
西邊有一個木製的建築物，上面掛著一個泛黃的招牌寫著幾個大
字，不過你似乎從未見過那種字體，北邊已經是被山丘所擋住而無去
路，南邊與東邊則是琰揚湖的步道，你可以看到有許多的邪獸正在一
旁爬行著。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-03",
"east":__DIR__"a-05",
"west":__DIR__"a-28",
]));
	setup();
}

 
