inherit ROOM;
void create() {
	set( "short", "$HIY$金色靈刀$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10032 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room696.c",
		"out"       : "/open/clan/ou-cloud-club/room/room138.c",
	]) );
	set( "long", @LONG

$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
