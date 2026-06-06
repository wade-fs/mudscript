inherit ROOM;
void create() {
	set( "short", "火行庫" );
	set( "owner", "apple" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
	]) );
	set( "build", 10081 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆~┌┬┐~☆☆┌┬┐~☆★★
★☆☆~├火┤☆☆~├行┤~☆☆├庫┤~☆☆★
★★☆~└┴┘☆☆~└┴┘~☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★


LONG);
	setup();
	replace_program(ROOM);
}
