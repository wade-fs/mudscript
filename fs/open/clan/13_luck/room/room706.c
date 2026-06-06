inherit ROOM;
void create() {
	set( "short", "三樓east" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/capital/obj/4-4",
		"file2"    : "/open/capital/obj/4-2",
		"amount5"  : 1,
		"file8"    : "/open/capital/obj/4-2",
		"file5"    : "/open/capital/obj/4-1",
		"file7"    : "/open/capital/obj/4-4",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/capital/obj/4-2",
		"amount9"  : 1,
		"file9"    : "/open/capital/obj/4-2",
		"file10"   : "/open/capital/obj/4-1",
		"file4"    : "/open/capital/obj/4-2",
		"amount10" : 1,
		"file1"    : "/open/capital/obj/4-2",
	]) );
	set( "build", 10003 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room713",
		"west"      : "/open/clan/13_luck/room/room661.c",
		"north"     : "/open/clan/13_luck/room/room710.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
