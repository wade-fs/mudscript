inherit ROOM;
void create() {
	set( "short", "聖境東三道" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 10083 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room5.c",
		"east"      : "/open/clan/free-zone/room/room17",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├東┤☆├三┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
