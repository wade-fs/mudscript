inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
這裡放置著一張木桌與許多的椅子，看來是供蛇寨的守衛休息的
地方，西邊有著一個石製的蛇雕，看起來栩栩如生。
LONG);
	set("exits",([
"east":__DIR__"r-03",
"north":__DIR__"r-11",
]));
	setup();
}
