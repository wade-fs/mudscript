inherit ROOM;
void create() {
	set( "short", "悟刀房" );
	set( "owner", "scs" );
	set( "object", ([
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 49,
		"amount1"  : 13,
		"amount3"  : 210,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file8"    : "/open/center/obj/clan-master-head",
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 5,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"file7"    : "/obj/stone/powder",
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/water-ball",
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10008 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room226",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
