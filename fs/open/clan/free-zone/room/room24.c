inherit ROOM;
void create() {
	set( "short", "木行庫" );
	set( "owner", "apple" );
	set( "object", ([
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
	]) );
	set( "build", 10273 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆~┌┬┐~☆☆┌┬┐~☆★★
★☆☆~├木┤☆☆~├行┤~☆☆├庫┤~☆☆★
★★☆~└┴┘☆☆~└┴┘~☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
