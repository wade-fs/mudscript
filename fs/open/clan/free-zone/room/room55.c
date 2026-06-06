inherit ROOM;
void create() {
	set( "short", "綠龍宮" );
	set( "object", ([
		"amount1"  : 500,
		"file1"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "owner", "fighter" );
	set( "build", 11025 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
