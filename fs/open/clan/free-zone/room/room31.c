inherit ROOM;
void create() {
	set( "short", "殺手傑庫" );
	set( "owner", "dragon" );
	set( "build", 10344 );
	set( "exits", ([
		"south"     : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├殺┤☆☆├手┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
