inherit ROOM;
void create() {
	set( "short", "無窮無盡" );
	set( "light_up", 1 );
	set( "object", ([
		"file9"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"amount5"  : 2,
		"file4"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/mogi/castle/obj/leave",
		"amount6"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file5"    : "/open/mogi/mountain/obj/frog-pill",
		"file8"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
	]) );
	set( "build", 10086 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room536",
	]) );
	set( "long", @LONG

無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無
無無無無無無無無無無無無無無無無無無無無無無無無無無無無
LONG);
	setup();
	replace_program(ROOM);
}
