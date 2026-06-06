inherit ROOM;
void create() {
	set( "short", "聖火傑庫" );
	set( "object", ([
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10257 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room30",
		"up"        : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├聖┤☆☆├火┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
