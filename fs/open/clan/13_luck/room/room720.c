inherit ROOM;
void create() {
	set( "short", "四樓northwest" );
	set( "owner", "zmud" );
	set( "build", 10134 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room716",
		"west"      : "/open/clan/13_luck/room/room717",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
