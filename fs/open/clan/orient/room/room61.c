inherit ROOM;
void create() {
	set( "short", "$YEL$= 土色靈爪 =$NOR$" );
	set( "owner", "fivewp" );
	set( "object", ([
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10051 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room62",
	]) );
	set( "long", @LONG
$YEL$土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
    土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
    土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
    土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
