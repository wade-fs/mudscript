inherit ROOM;
void create() {
	set( "short", "cowboy's room" );
	set( "owner", "cowboy" );
	set( "build", 12112 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room685.c",
		"west"      : "/open/clan/ou-cloud-club/room/room699",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
