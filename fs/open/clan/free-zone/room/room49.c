inherit ROOM;
void create() {
	set( "short", "匕煉房" );
	set( "build", 10066 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room48",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆┌┬┐☆☆┌┬┐~☆★★
★☆☆~├匕┤☆☆├煉┤☆☆├房┤~☆☆★
★★☆~└┴┘☆☆└┴┘☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
