inherit ROOM;
void create() {
	set( "short", "五塔準備房" );
	set( "object", ([
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount7"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount3"  : 1,
	]) );
	set( "build", 10099 );
	set( "owner", "cdrom" );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room658",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
