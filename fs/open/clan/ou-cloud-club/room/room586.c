inherit ROOM;
void create() {
	set( "short", "來到南" );
	set( "owner", "dking" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 7690 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room565",
	]) );
	set( "long", @LONG
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
這裡是南邊 這裡是南邊 這裡是南邊 這裡是南邊
LONG);
	setup();
	replace_program(ROOM);
}
