inherit ROOM;
void create() {
	set( "short", "新區域J-EN" );
	set( "object", ([
		"amount5"  : 43,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 40,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount1"  : 1,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/snow/obj/snow_token",
		"amount2"  : 40,
		"amount4"  : 44,
	]) );
	set( "owner", "snowy" );
	set( "build", 10140 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room578",
		"south"     : "/open/clan/ou-cloud-club/room/room576.c",
		"out"       : "/open/clan/ou-cloud-club/room/room80.c",
		"north"     : "/open/clan/ou-cloud-club/room/room577.c",
		"east"      : "/open/clan/ou-cloud-club/room/room575.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
