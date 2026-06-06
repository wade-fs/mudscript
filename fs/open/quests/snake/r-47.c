inherit ROOM;

void create()
{
	set("short","蛇寨 中廳");
	set("long",@LONG
在一旁可以看到許多的蛇籠，籠內放置著一些身體顏色鮮豔的蛇
類，一些你從未看過的蛇種，直覺上你就能夠猜測到那些蛇都帶有劇
毒，還是不要碰的好。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":1,
]));
	set("exits",([
"east":__DIR__"r-48",
"west":__DIR__"r-46",
"south":__DIR__"r-50",
]));
	setup();
}
