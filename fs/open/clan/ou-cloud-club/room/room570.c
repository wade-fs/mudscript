inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIB$魔$HIC$神$HIW$殿$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/seven4-dark-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 15113 );
	set( "owner", "left" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room567",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
