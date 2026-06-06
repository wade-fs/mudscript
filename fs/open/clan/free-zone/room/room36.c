inherit ROOM;
void create() {
	set( "short", "段家傑庫" );
	set( "owner", "dragon" );
	set( "build", 10479 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room33",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├段┤☆☆├家┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
