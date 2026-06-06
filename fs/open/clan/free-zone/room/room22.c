inherit ROOM;
void create() {
	set( "short", "八傑寶庫" );
	set( "owner", "dragon" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "build", 14481 );
	set( "exits", ([
		"enter"     : "/open/clan/free-zone/room/room33",
		"east"      : "/open/clan/free-zone/room/room20.c",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├八┤☆☆├傑┤☆☆├寶┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
