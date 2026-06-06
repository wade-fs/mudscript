inherit ROOM;
void create() {
	set( "short", "enter" );
	set( "exits", ([
		"out"       : "/open/clan/dark-forest/room/hall",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
