inherit ROOM;
void create() {
	set( "short", "scs's place" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount1"  : 130,
		"file4"    : "/open/firedancer/npc/eq/r_neck",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount10" : 1,
		"amount2"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10023 );
	set( "owner", "scs" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room226",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
