inherit ROOM;
void create() {
	set( "short", "土行四" );
	set( "object", ([
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/obj/gift/xisuidan",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10039 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room625",
	]) );
	set( "long", @LONG
等我有空吧.......................................
等我有空吧.......................................
等我有空吧.......................................
等我有空吧.......................................
LONG);
	setup();
	replace_program(ROOM);
}
