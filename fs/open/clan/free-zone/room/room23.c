inherit ROOM;
void create() {
	set( "short", "金行庫" );
	set( "owner", "dragon" );
	set( "object", ([
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10772 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆~┌┬┐~☆☆┌┬┐~☆★★
★☆☆~├金┤☆☆~├行┤~☆☆├庫┤~☆☆★
★★☆~└┴┘☆☆~└┴┘~☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
