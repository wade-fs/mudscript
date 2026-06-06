inherit ROOM;
void create() {
	set( "short", "十二星宮" );
	set( "object", ([
		"file4"    : "/open/mon/obj/mon-pill",
		"amount2"  : 158,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 163,
		"amount3"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/killer/obj/atman_pill",
		"amount1"  : 204,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "owner", "jar" );
	set( "build", 10018 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room190",
		"south"     : "/open/clan/time-limit/room/room83.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
