inherit ROOM;
void create() {
	set( "short", "土行五" );
	set( "object", ([
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room625",
	]) );
	set( "long", @LONG
等我有空吧.......................................
等我有空吧.......................................
等我有空吧.......................................
等我有空吧.......................................
等我有空吧.......................................
LONG);
	setup();
	replace_program(ROOM);
}
