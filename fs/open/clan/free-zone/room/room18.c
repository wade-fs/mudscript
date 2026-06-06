inherit ROOM;
void create() {
	set( "short", "聖境西四道" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/magic-sign",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 11349 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room8",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├西┤☆├四┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
