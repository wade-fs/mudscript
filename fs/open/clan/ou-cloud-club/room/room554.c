inherit ROOM;
void create() {
	set( "short", "warhammer3" );
	set( "owner", "freeman" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room552",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
