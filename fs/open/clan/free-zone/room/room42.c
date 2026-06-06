inherit ROOM;
void create() {
	set( "short", "南城東古道小徑" );
	set( "build", 12765 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room43",
		"west"      : "/open/clan/free-zone/room/room41",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
