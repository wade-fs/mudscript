inherit ROOM;
void create() {
	set( "short", "九轉熊蛇丸" );
	set( "object", ([
		"file9"    : "/open/ping/obj/poison_pill",
		"amount8"  : 635,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount2"  : 880,
		"file6"    : "/open/ping/obj/poison_pill",
		"amount3"  : 790,
		"amount7"  : 748,
		"file4"    : "/open/ping/obj/poison_pill",
		"file7"    : "/open/ping/obj/poison_pill",
		"file5"    : "/open/ping/obj/poison_pill",
		"amount1"  : 856,
		"file8"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/ping/obj/poison_pill",
		"amount4"  : 755,
		"amount9"  : 1042,
		"amount6"  : 857,
		"amount5"  : 802,
		"file10"   : "/open/ping/obj/poison_pill",
		"amount10" : 748,
	]) );
	set( "owner", "fighter" );
	set( "build", 10256 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room59.c",
		"west"      : "/open/clan/free-zone/room/room63",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
