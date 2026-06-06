inherit ROOM;
void create() {
	set( "short", "大潤發" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount5"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/dragon/obj/wind-1",
		"file8"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"amount1"  : 152,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 500,
		"file9"    : "/open/start/obj/k_cloth",
		"file3"    : "/open/mogi/dragon/obj/fire-1",
		"amount4"  : 1,
	]) );
	set( "build", 10178 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room121",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
