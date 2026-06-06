inherit ROOM;
void create() {
	set( "short", "新區域J-S" );
	set( "owner", "snowy" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 15289 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room574",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
