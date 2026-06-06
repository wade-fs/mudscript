inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    地上有有好幾個骨骸，有的是看的出來是動物或人類的屍體，有
的就看不出來是哪種生物的骨骸，看的出來是被某種生物「吃掉」剩
下來的殘渣，似乎有某種專吃肉類的生物存在！
LONG);
	set("exits",([
		"east":__DIR__"u08",
		"north":__DIR__"u12",
		"south":__DIR__"u13",
		"west":__DIR__"u14",
	]));
	set("no_transmit",1);
	setup();
}
