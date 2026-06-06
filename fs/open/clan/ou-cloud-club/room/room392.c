inherit ROOM;
void create() {
	set( "short", "$HIB$--虹晶疾風護膝--$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount3"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount4"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_legging",
		"file4"    : "/open/ping/questsfan/obj/diamond_legging",
	]) );
	set( "build", 12927 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room391",
		"west"      : "/open/clan/ou-cloud-club/room/room396",
	]) );
	set( "long", @LONG
疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝虹晶疾風護膝
LONG);
	setup();
	replace_program(ROOM);
}
