inherit ROOM;
void create() {
	set( "short", "土行庫" );
	set( "owner", "apple" );
	set( "object", ([
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
	]) );
	set( "build", 12038 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆~┌┬┐~☆☆┌┬┐~☆★★
★☆☆~├土┤☆☆~├行┤~☆☆├庫┤~☆☆★
★★☆~└┴┘☆☆~└┴┘~☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★


LONG);
	setup();
	replace_program(ROOM);
}
