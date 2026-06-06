inherit ROOM;
void create() {
	set( "short", "hild預定地Ⅱ" );
	set( "owner", "working" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
	]) );
	set( "build", 11852 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room66",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
