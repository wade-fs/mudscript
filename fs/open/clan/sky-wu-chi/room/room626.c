inherit ROOM;
void create() {
	set( "short", "土行三" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10061 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room625",
	]) );
	set( "long", @LONG
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦
LONG);
	setup();
	replace_program(ROOM);
}
