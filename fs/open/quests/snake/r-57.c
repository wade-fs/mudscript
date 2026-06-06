inherit ROOM;

void create()
{
	set("short","蛇寨 迴廊");
	set("long",@LONG
這裡是一個陰暗的迴廊，你身在迴廊中，偶爾會聽到吵雜的交談
聲，看來你似乎離蛇寨的中心不遠了。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":3,
]));
	set("exits",([
"east":__DIR__"r-56",
"up":__DIR__"r-58",
]));
	setup();
}
