inherit ROOM;
void create() {
	set( "short", "cowboy's room" );
	set( "build", 11664 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room698.c",
		"west"      : "/open/clan/ou-cloud-club/room/room700",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
