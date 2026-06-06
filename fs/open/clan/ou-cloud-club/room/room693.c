inherit ROOM;
void create() {
	set( "short", "$HIC$水色靈帶$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10351 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room694",
		"west"      : "/open/clan/ou-cloud-club/room/room692.c",
	]) );
	set( "long", @LONG

$HIC$水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶$NOR$
$HIC$水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶$NOR$
$HIC$水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶$NOR$
$HIC$水色靈帶水色靈帶水色靈帶水色靈帶水色靈帶$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
