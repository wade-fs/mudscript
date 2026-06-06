inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
在一旁有許多販賣著小吃的邪獸，你興致勃勃的錢去看望，只見
上面放滿了許多的蠱蟲、腐肉，臉色一垮，趕緊的走回步道...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-12",
"north":__DIR__"a-10",
]));
	setup();
}

 
