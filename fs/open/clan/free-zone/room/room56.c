inherit ROOM;
void create() {
	set( "short", "白龍宮" );
	set( "build", 10970 );
	set( "exits", ([
		"east"      : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
