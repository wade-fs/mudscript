inherit ROOM;

void create()
{
	set("short","蛇寨 三層大廳");
	set("long",@LONG
通道上，擠滿了許多種類的毒蛇，不過大多不會攻擊人，而通道
上卻擺滿了許多雕刻精美的石雕，石雕雕碩之精美，連他臉上的皺折
都可以清晰的看見，但是..似乎都不像是人間界的生物石雕..
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/snake_guard_1":1,
__DIR__"npc/snake_guard_2":1,
]));
	set("exits",([
"south":__DIR__"r-65",
"north":__DIR__"r-67",
]));
	setup();
}

int valid_leave(object me,string dir)
{
	if( present("snake-guard",environment(me)) )
	{
		message_vision("長老大喝："+me->name(1)+"想往哪跑～給我站住～\n",me);
		return notify_fail("你的退路已經被擋住了。\n");
	}
return 1;
}
