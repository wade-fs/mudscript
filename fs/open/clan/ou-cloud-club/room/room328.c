inherit ROOM;
void create() {
	set( "short", "西洋古董洋果子店" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount10" : 1,
		"file1"    : "/obj/gift/xiandan",
		"file10"   : "/open/prayer/obj/boris-cloth",
		"file4"    : "/open/ping/obj/chilin_legging",
		"file8"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file9"    : "/open/dancer/obj/maple_ribbon",
	]) );
	set( "build", 20484 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room121.c",
		"add"       : "/open/clan/ou-cloud-club/room/room356",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
