inherit ROOM;
void create() {
	set( "short", "醉仙二樓east" );
	set( "object", ([
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 11066 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/nine-sky-dragon/room/room15",
		"west"      : "/open/clan/nine-sky-dragon/room/room14",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
