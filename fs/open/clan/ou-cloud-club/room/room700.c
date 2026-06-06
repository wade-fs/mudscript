inherit ROOM;
void create() {
	set( "short", "最新" );
	set( "owner", "cowboy" );
	set( "build", 11267 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room699",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
