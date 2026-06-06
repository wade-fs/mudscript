inherit ROOM;

void create()
{
	set("short","蛇寨 三層大廳");
	set("long",@LONG
雖然不是很清楚，但你可以確定北邊有一座批著大蛇皮的座椅，
似乎是蛇寨寨主的座椅，不過要通往那路上，似乎有許多的高手正在
等待著你自投羅網。。
LONG);
	set("objects",([
__DIR__"npc/crazy_snake":1,
__DIR__"npc/poison_soldier":1,
__DIR__"npc/snake_soldier":1,
]));
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"r-64",
"west":__DIR__"r-62",
"north":__DIR__"r-65",
]));
	setup();
}
