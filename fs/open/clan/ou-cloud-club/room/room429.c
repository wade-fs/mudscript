inherit ROOM;
void create() {
	set( "short", "$HIY$金色靈刀$NOR$" );
	set( "object", ([
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10560 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room475",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
$HIY$靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
