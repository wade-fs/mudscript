inherit ROOM;
void create() {
	set( "short", "藏豆" );
	set( "build", 10001 );
	set( "owner", "bior" );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room40",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
