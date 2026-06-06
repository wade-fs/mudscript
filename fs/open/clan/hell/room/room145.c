inherit ROOM;
void create() {
	set( "short", "新區域" );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room146",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
