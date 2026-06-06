inherit ROOM;
void create() {
	set( "short", "紫龍宮" );
	set( "build", 12545 );
	set( "exits", ([
		"up"        : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
