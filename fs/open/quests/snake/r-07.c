inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
這是蛇寨的左階梯，往東回到蛇寨的大門入口。
LONG);
	set("exits",([
"east":__DIR__"r-02",
"up":__DIR__"r-13",
]));
	setup();
}
