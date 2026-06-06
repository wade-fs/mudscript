inherit ROOM;
void create() {
	set( "short", "聖境北四街" );
	set( "build", 10049 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room14",
	]) );
	set( "long", @LONG

☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆
★~┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐☆┌┬┐★
☆~├聖┤☆├境┤☆├北┤☆├四┤☆├街┤☆
★~└┴┘☆└┴┘☆└┴┘☆└┴┘☆└┴┘★
☆★☆★☆★☆★☆★☆★☆~★☆★☆★☆★☆ 


LONG);
	setup();
	replace_program(ROOM);
}
