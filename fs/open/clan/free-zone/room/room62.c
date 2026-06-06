inherit ROOM;
void create() {
	set( "short", "靈芝仙丹" );
	set( "object", ([
		"amount1"  : 625,
		"file1"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "owner", "fighter" );
	set( "build", 10336 );
	set( "exits", ([
		"north"     : "/open/clan/free-zone/room/room59",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
