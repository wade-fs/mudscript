inherit ROOM;
void create() {
	set( "short", "$YEL$土色靈爪$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10090 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room697",
		"west"      : "/open/clan/ou-cloud-club/room/room695.c",
	]) );
	set( "long", @LONG

$YEL$土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪$NOR$
$YEL$土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪$NOR$
$YEL$土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪$NOR$
$YEL$土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
