inherit ROOM;
void create() {
	set( "short", "寨口" );
	set( "exits", ([
		"out"       : "/open/clan/nine-sky-dragon/room/room19",
	]) );
	set( "owner", "dolphin" );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
