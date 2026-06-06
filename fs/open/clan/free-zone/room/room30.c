inherit ROOM;
void create() {
	set( "short", "仙劍傑庫" );
	set( "owner", "dragon" );
	set( "build", 10915 );
	set( "exits", ([
		"up"        : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├仙┤☆☆├劍┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
