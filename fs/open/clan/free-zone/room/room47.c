inherit ROOM;
void create() {
	set( "short", "拳煉房" );
	set( "build", 10680 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room46",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆┌┬┐☆☆┌┬┐~☆★★
★☆☆~├拳┤☆☆├煉┤☆☆├房┤~☆☆★
★★☆~└┴┘☆☆└┴┘☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
