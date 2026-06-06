inherit ROOM;

void create()
{
	set("short","蛇寨 二層暗道");
	set("long",@LONG
陰暗且潮濕，是你對這整個蛇寨最大的映像，這裡不外乎也是如
此，往南通往蛇寨前棟二層休息處。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":2,
__DIR__"npc/poison_soldier":2,
]));
	set("exits",([
"up":__DIR__"r-64",
"south":__DIR__"r-14",
]));
	setup();
}

int valid_leave(object me,string dir)
{
	if( present("snake-soldier",environment(me)) )
	{
		message_vision("守衛大喝：兄弟們～別讓"+me->name(1)+"跑了～\n",me);
		return notify_fail("你的退路已經被擋住了。\n");
	}
	if( dir == "south" )
		message_vision("$N一不小心，滑了出去～\n",me);
return 1;
}
