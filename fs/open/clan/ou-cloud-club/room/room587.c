inherit ROOM;
void create() {
	set( "short", "來到北" );
	set( "owner", "dking" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/butterfly",
		"file6"    : "/open/magic-manor/ghost/obj/five-turn-ball",
	]) );
	set( "build", 14216 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room565",
	]) );
	set( "long", @LONG
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
這裡是北邊 這裡是北邊 這裡是北邊 這裡是北邊
LONG);
	setup();
	replace_program(ROOM);
}
