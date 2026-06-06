inherit ROOM;
void create() {
	set( "short", "青龍舞天" );
	set( "owner", "mad" );
	set( "object", ([
		"file3"    : "/open/ping/obj/chilin_legging",
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"file2"    : "/open/ping/obj/gold_hand",
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"amount2"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"amount1"  : 1,
		"amount3"  : 1,
		"file9"    : "/daemon/class/blademan/obj/ublade",
		"file1"    : "/open/ping/obj/chilin_legging",
		"amount4"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 16398 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room19.c",
		"up"        : "/open/clan/13_luck/room/room21",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    上了青龍之階你往下一看已經離地好幾丈，你想如果在這被襲擊大
概是很難活命的，再往上一看總覺得的很長好遠怎麼爬也爬不完，不過
你倒可以欣賞一下外頭的風景，可以看到漂亮的柳月泉，也可以看到雪
白的天山這是你從沒慢慢欣賞的，可以陪你渡過這次的階之旅。

LONG);
	setup();
	replace_program(ROOM);
}
