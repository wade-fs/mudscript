inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    這裡有一道地底河流，由於光線昏暗，你無法確定水質是否清澈
，隱約中可以聽到水流聲，如果跳下去(jump)，應該可以通往外界！
LONG);
	set("exits",([
		"south":__DIR__"u11",
	]));
	set("no_transmit",1);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump()
{
	object me = this_player();
	message_vision("$N跳下河去，被水沖走了！\n",me);
	me->move("/open/area/forest/a10");
	return 1;
}
