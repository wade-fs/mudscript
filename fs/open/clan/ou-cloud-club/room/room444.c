inherit ROOM;
void create() {
	set( "short", "維克後宮" );
	set( "owner", "vicker" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/ping/obj/chilin_legging",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/flower-claw",
		"file3"    : "/open/capital/guard/gring",
	]) );
	set( "build", 10014 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room420",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
