inherit ROOM;
void create() {
	set( "short", "$HIC$水色緞帶$NOR$" );
	set( "object", ([
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10614 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room162.c",
		"west"      : "/open/clan/ou-cloud-club/room/room477.c",
		"east"      : "/open/clan/ou-cloud-club/room/room475",
	]) );
	set( "long", @LONG
緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶
水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶
水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶
水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶
水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶
水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶水色緞帶

LONG);
	setup();
	replace_program(ROOM);
}
