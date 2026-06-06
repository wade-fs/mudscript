inherit ROOM;
void create() {
	set( "short", "來到東邊" );
	set( "owner", "dking" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/ping/obj/cloud",
	]) );
	set( "build", 10209 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room565",
	]) );
	set( "long", @LONG
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
這裡是東邊 這裡是東邊 這裡是東邊 這裡是東邊
LONG);
	setup();
	replace_program(ROOM);
}
