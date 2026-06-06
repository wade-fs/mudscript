inherit ROOM;
void create() {
	set( "short", "刀煉房" );
	set( "build", 10072 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room44",
	]) );
	set( "long", @LONG

★★★☆★☆★☆★☆★☆★☆★☆★★☆★
★★☆~┌┬┐☆☆┌┬┐☆☆┌┬┐~☆★★
★☆☆~├刀┤☆☆├煉┤☆☆├房┤~☆☆★
★★☆~└┴┘☆☆└┴┘☆☆└┴┘~☆★★
★★☆★☆★☆★☆★☆★☆★☆★★★☆★

LONG);
	setup();
	replace_program(ROOM);
}
