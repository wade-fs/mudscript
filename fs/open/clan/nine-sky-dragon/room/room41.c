inherit ROOM;
void create() {
	set( "short", "聖火鬥士-豆火" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"file7"    : "/open/killer/obj/fire-knife",
		"file6"    : "/open/capital/obj/4-1",
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10026 );
	set( "owner", "bior" );
	set( "exits", ([
		"enter"     : "/open/clan/nine-sky-dragon/room/room40",
		"west"      : "/open/clan/nine-sky-dragon/room/room13",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
