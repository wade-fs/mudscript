inherit ROOM;
void create() {
	set( "short", "四樓southeast" );
	set( "owner", "zmud" );
	set( "build", 10001 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room715",
		"north"     : "/open/clan/13_luck/room/room716",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
