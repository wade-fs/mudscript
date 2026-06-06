inherit ROOM;
void create() {
	set( "short", "聖境東四道" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10553 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room6",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├東┤☆├四┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
