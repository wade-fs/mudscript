inherit ROOM;
void create() {
	set( "short", "百花清心露" );
	set( "object", ([
		"amount10" : 924,
		"file5"    : "/open/ping/obj/poison_pill",
		"amount2"  : 868,
		"file10"   : "/open/ping/obj/poison_pill",
		"amount3"  : 717,
		"amount4"  : 803,
		"file7"    : "/open/ping/obj/poison_pill",
		"amount7"  : 837,
		"amount1"  : 770,
		"file6"    : "/open/ping/obj/poison_pill",
		"amount5"  : 886,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount6"  : 831,
		"amount9"  : 976,
		"file3"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/ping/obj/poison_pill",
		"amount8"  : 823,
	]) );
	set( "owner", "fighter" );
	set( "build", 11575 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room59",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
