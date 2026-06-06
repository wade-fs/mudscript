inherit ROOM;
void create() {
	set( "short", "聖境西三道" );
	set( "object", ([
		"file10"   : "/obj/gift/xisuidan",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"file7"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 11507 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room18",
		"east"      : "/open/clan/free-zone/room/room7.c",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├西┤☆├三┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
