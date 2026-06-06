inherit ROOM;
void create() {
	set( "short", "醉仙二樓" );
	set( "object", ([
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10336 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room16.c",
		"down"      : "/open/clan/nine-sky-dragon/room/room11.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room19",
		"north"     : "/open/clan/nine-sky-dragon/room/room17.c",
		"west"      : "/open/clan/nine-sky-dragon/room/room18.c",
		"up"        : "/open/clan/nine-sky-dragon/room/room13.c",
	]) );
	set( "long", @LONG

　　你繞過一道淡綠綢屏風，順著樓梯來到醉仙樓二樓的走郎上，心
情愉悅地走著。往外望去，百花盛開，紅綠相映，美不勝收。千里黃
鶯鳴唱，十分悅耳。往裡望去，醉仙樓內，小二忙裡忙外，忙著招呼
客人，人聲頂沸十分吵雜。

LONG);
	setup();
	replace_program(ROOM);
}
