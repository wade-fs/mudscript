inherit ROOM;
void create() {
	set( "short", "生生造化丹" );
	set( "object", ([
		"file9"    : "/open/ping/obj/poison_pill",
		"file7"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"amount9"  : 784,
		"amount1"  : 1,
		"file10"   : "/open/ping/obj/poison_pill",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount10" : 846,
		"amount3"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "owner", "fighter" );
	set( "build", 10495 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room61",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
