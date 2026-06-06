inherit ROOM;
void create() {
	set( "short", "三樓northwest" );
	set( "owner", "zmud" );
	set( "build", 10035 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room707.c",
		"east"      : "/open/clan/13_luck/room/room708",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
