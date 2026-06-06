inherit ROOM;
void create() {
	set( "short", "三樓north" );
	set( "owner", "zmud" );
	set( "build", 10002 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room661.c",
		"west"      : "/open/clan/13_luck/room/room711",
		"east"      : "/open/clan/13_luck/room/room710.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
