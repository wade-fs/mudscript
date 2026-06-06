inherit ROOM;
void create() {
	set( "short", "四樓west" );
	set( "owner", "zmud" );
	set( "build", 10043 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room719",
		"east"      : "/open/clan/13_luck/room/room660.c",
		"north"     : "/open/clan/13_luck/room/room718.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
