inherit ROOM;
void create() {
	set( "short", "晶圓房" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room431",
		"north"     : "/open/clan/ou-cloud-club/room/room617",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
