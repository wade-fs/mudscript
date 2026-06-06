inherit ROOM;
void create() {
	set( "short", "龍王宮" );
	set( "object", ([
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "owner", "fighter" );
	set( "build", 12094 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
