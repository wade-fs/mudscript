inherit ROOM;
void create() {
	set( "short", "四樓northwest" );
	set( "owner", "djlh" );
	set( "build", 10045 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room714",
		"east"      : "/open/clan/13_luck/room/room717",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
