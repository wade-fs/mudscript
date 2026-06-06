inherit ROOM;
void create() {
	set( "short", "水行庫" );
	set( "owner", "dragon" );
	set( "build", 10042 );
	set( "exits", ([
		"out"       : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆~┌┬┐~☆☆┌┬┐~☆★★
★☆☆~├水┤☆☆~├行┤~☆☆├庫┤~☆☆★
★★☆~└┴┘☆☆~└┴┘~☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
