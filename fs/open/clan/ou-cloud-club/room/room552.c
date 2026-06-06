inherit ROOM;
void create() {
	set( "short", "warhammer1" );
	set( "owner", "warhammer" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room171.c",
		"east"      : "/open/clan/ou-cloud-club/room/room554",
		"west"      : "/open/clan/ou-cloud-club/room/room553.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
