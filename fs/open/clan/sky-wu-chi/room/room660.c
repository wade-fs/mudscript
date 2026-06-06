inherit ROOM;
void create() {
	set( "short", "五塔準備房" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10002 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room658",
	]) );
	set( "owner", "cdrom" );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
