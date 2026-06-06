inherit ROOM;
void create() {
	set( "short", "三樓northeast" );
	set( "owner", "zmud" );
	set( "build", 10013 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room706.c",
		"west"      : "/open/clan/13_luck/room/room708",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
