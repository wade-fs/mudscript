inherit ROOM;
void create() {
	set( "short", "混合豆" );
	set( "build", 10072 );
	set( "owner", "bior" );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room40",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
