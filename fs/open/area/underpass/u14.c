inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    這裡空蕩蕩的，什麼東西都沒有！
LONG);
	set("exits",([
		"east":__DIR__"u11",
	]));
	set("no_transmit",1);
	setup();
}

void init()
{
	message_vision("腳底突然一軟，$N開始往下墜！\n",this_player());
	this_player()->move(__DIR__"a01");
}
