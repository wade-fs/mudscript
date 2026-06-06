inherit ROOM;
void create() {
	set( "short", "聖境東二道" );
	set( "owner", "dragon" );
	set( "object", ([
		"amount5"  : 400,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 400,
		"amount6"  : 400,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 400,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 400,
	]) );
	set( "build", 11211 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room3.c",
		"east"      : "/open/clan/free-zone/room/room6",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├東┤☆├二┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
