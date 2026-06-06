inherit ROOM;
void create() {
	set( "short", "世間雷道" );
	set( "owner", "amdxp" );
	set( "build", 10236 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room297.c",
		"south"     : "/open/clan/13_luck/room/room322",
		"east"      : "/open/clan/13_luck/room/room299.c",
		"north"     : "/open/clan/13_luck/room/room269",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五候道，此道為雷
道，用來比喻十三吉祥的威力，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
