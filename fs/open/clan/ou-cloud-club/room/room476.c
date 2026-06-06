inherit ROOM;
void create() {
	set( "short", "$YEL$土色靈爪$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
	]) );
	set( "build", 10492 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room477",
	]) );
	set( "long", @LONG
靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪
土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪土色靈爪

LONG);
	setup();
	replace_program(ROOM);
}
