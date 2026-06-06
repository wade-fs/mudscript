inherit ROOM;
void create() {
	set( "short", "南城近郊東古道" );
	set( "build", 10041 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room42",
		"west"      : "/open/clan/free-zone/room/room40.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
