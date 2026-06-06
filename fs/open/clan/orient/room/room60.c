inherit ROOM;
void create() {
	set( "short", "$HIY$= 金色靈刀 =$NOR$" );
	set( "owner", "fivewp" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10193 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room59",
		"east"      : "/open/clan/orient/room/room63.c",
	]) );
	set( "long", @LONG
$HIY$金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀
    金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀
    金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀
    金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀金色靈刀$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
