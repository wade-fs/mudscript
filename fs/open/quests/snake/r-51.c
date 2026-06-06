inherit ROOM;

void create()
{
	set("short","蛇寨 中廳");
	set("long",@LONG
在你的正北方擺設著一隻石雕大蛇，兩旁則不斷的傳來陣陣的血
腥味與藥水味，往南則有一個迴廊，通往蛇寨二層。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":2,
]));
	set("exits",([
"east":__DIR__"r-50",
"west":__DIR__"r-52",
"south":__DIR__"r-56",
]));
	setup();
}
