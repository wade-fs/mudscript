inherit ROOM;
void create() {
	set( "short", "五塔準備房" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
	]) );
	set( "build", 10637 );
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
