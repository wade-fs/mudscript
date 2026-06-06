inherit ROOM;
void create() {
	set( "short", "$HIC$= 水色靈帶 =$NOR$" );
	set( "owner", "fivewp" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10049 );
	set( "exits", ([
		"out"       : "/open/clan/orient/room/hall",
		"west"      : "/open/clan/orient/room/room60.c",
		"east"      : "/open/clan/orient/room/room62.c",
	]) );
	set( "long", @LONG
$HIC$水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶
    水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶
    水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶
    水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
