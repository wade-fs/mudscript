inherit ROOM;
void create() {
	set( "short", "南城近郊" );
	set( "owner", "superblade" );
	set( "build", 12649 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room41",
		"north"     : "/open/clan/free-zone/room/room39",
	]) );
	set( "long", @LONG

 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★
★~╭┬┐☆☆╭┬┐☆☆╭┬┐☆☆╭┬┐~★
☆~├南┤☆☆├城┤☆☆├近┤☆☆├郊┤~☆
★~└┴┘☆☆└┴┘☆☆└┴┘☆☆└┴┘~★
 ★☆★☆★☆☆★☆★☆☆★☆★☆☆★☆★

LONG);
	setup();
	replace_program(ROOM);
}
