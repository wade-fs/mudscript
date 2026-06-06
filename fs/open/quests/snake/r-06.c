inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
這是蛇寨的右階梯，往西回到蛇寨的大門入口。
LONG);
	set("exits",([
"west":__DIR__"r-02",
"up":__DIR__"r-15",
]));
	setup();
}
