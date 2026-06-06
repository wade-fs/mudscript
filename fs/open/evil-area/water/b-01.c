inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居"NOR);
	set("long",@LONG
琰揚居是位於琰揚湖上的一個建築物，外觀富麗堂皇，在人間而
言，裡面住的一定是達官貴人，可是，這裡面可謂之家徒四壁，一點
有價值的東西都沒有，除了那亮麗的外觀以外...
你目前正佇立於琰揚居的廳堂，往南前往大廳中央，往西通往廚房，
往外走就是琰揚湖的同心橋。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"out":__DIR__"a-26",
"east":__DIR__"b-02",
"south":__DIR__"b-09",
]));
	setup();
}

 
