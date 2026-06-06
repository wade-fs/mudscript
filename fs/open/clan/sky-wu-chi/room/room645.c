inherit ROOM;
void create() {
	set( "short", "金行二" );
	set( "object", ([
		"amount6"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 6116 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room644",
	]) );
	set( "long", @LONG
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
懶的寫....................................................
LONG);
	setup();
	replace_program(ROOM);
}
