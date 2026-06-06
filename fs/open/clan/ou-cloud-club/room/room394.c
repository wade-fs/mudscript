inherit ROOM;
void create() {
	set( "short", "$HIM$--虹晶頭釵--$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount3"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file1"    : "/open/ping/questsfan/obj/diamond_hairpin",
	]) );
	set( "build", 10039 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room395.c",
		"west"      : "/open/clan/ou-cloud-club/room/room393",
	]) );
	set( "long", @LONG
頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵虹晶頭釵
LONG);
	setup();
	replace_program(ROOM);
}
