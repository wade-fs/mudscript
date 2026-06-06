inherit ROOM;
void create() {
	set( "short", "南城試煉塔大門" );
	set( "build", 12635 );
	set( "exits", ([
		"enter"     : "/open/clan/free-zone/room/room44",
		"west"      : "/open/clan/free-zone/room/room42.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
