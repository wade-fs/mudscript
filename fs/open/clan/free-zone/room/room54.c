inherit ROOM;
void create() {
	set( "short", "黃龍宮" );
	set( "build", 10857 );
	set( "exits", ([
		"north"     : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
