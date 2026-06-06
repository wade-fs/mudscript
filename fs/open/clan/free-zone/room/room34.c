inherit ROOM;
void create() {
	set( "short", "惡人傑庫" );
	set( "owner", "dragon" );
	set( "build", 10736 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room33.c",
		"up"        : "/open/clan/free-zone/room/room36",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├惡┤☆☆├人┤☆☆├傑┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★


LONG);
	setup();
	replace_program(ROOM);
}
