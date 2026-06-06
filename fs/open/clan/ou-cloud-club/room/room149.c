inherit ROOM;
void create() {
	set( "short", "小寶神龍教" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/port/obj/wolf_ring",
		"amount1"  : 1,
		"file1"    : "/open/ping/obj/ring-2",
	]) );
	set( "owner", "weishoubow" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room400",
	]) );
	set( "build", 10343 );
	set( "light_up", 1 );
	set( "long", @LONG
------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------


LONG);
	setup();
	replace_program(ROOM);
}
