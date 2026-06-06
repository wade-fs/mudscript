inherit ROOM;
void create() {
	set( "short", "霧之林小徑" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room168",
		"south"     : "/open/clan/13_luck/room/room169.c",
		"west"      : "/open/clan/13_luck/room/room182.c",
		"north"     : "/open/clan/13_luck/room/room168.c",
		"down"      : "/open/clan/13_luck/room/room167",
	]) );
	set( "long", @LONG

　　一條被野草覆蓋的小路，使你不得用手撥開草叢才能通行，加上
漫天的白霧，可以想像的到這條小徑是多麼的難走，使你不得不小心
亦亦的往前。越靠近洞穴，那稀稀嗦嗦的聲音就越來越大聲，使你不
得不提高警覺，以防任何狀況發生。

LONG);
	setup();
	replace_program(ROOM);
}
