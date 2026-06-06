inherit ROOM;
void create() {
	set( "short", "princess's room" );
	set( "light_up", 1 );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 8,
		"file2"    : "/open/mon/obj/mon-pill",
		"amount1"  : 5,
	]) );
	set( "build", 10098 );
	set( "owner", "princess" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room192",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
