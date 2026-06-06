inherit ROOM;
void create() {
	set( "short", "聖境東一道" );
	set( "owner", "hellokitty" );
	set( "object", ([
		"amount2"  : 465,
		"amount9"  : 578,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount4"  : 479,
	]) );
	set( "build", 10628 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/hall",
		"east"      : "/open/clan/free-zone/room/room5",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├東┤☆├一┤☆├道┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 

LONG);
	setup();
	replace_program(ROOM);
}
