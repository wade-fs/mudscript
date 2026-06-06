inherit ROOM;
void create() {
	set( "short", "笨蛋不得入內" );
	set( "owner", "acelan" );
	set( "build", 10212 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room121",
		"west"      : "/open/clan/hell/room/room123.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
