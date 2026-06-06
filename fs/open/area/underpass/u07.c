inherit ROOM;

void create()
{
        set("short","地下通道");
        set("long",@LONG
    地上的腳印非常的多，彷彿有幾十條蚯蚓與蜈蚣到處亂竄，經過
剛剛的那段戰鬥，你漸漸的感到吃力，如果在這狹窄的地方遇到大量
的敵人，真的是死路一條！
LONG);
        set("exits",([
        "east":__DIR__"u06",
        "west":__DIR__"u08",
        ]));
        set("objects",([
        __DIR__"npc/earthworm":2,
        __DIR__"npc/chimaera":2,
        __DIR__"npc/shadow-killer":2,
        ]));
        set("no_transmit",1);
        setup();
}

int valid_leave(object me,string dir)
{
	object env=environment(me);
	
	if(dir=="west")
	{
		if( present("shadow",env) || present("chimaera",env) || present("earthworm",env) )
			return notify_fail("你要前往的通道被擋住了！\n");
	}
return 1;
}
