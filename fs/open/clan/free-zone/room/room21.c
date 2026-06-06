inherit ROOM;
void create() {
	set( "short", "五行寶庫" );
	set( "owner", "dragon" );
	set( "build", 11420 );
	set( "exits", ([
		"water"     : "/open/clan/free-zone/room/room26.c",
		"up"        : "/open/clan/free-zone/room/room64",
		"soil"      : "/open/clan/free-zone/room/room27",
		"fire"      : "/open/clan/free-zone/room/room25.c",
		"gold"      : "/open/clan/free-zone/room/room23.c",
		"wood"      : "/open/clan/free-zone/room/room24.c",
		"west"      : "/open/clan/free-zone/room/room20.c",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├五┤☆☆├行┤☆☆├寶┤☆☆├庫┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
