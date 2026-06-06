inherit ROOM;
void create() {
	set( "short", "擊豆" );
	set( "build", 10021 );
	set( "owner", "bior" );
	set( "exits", ([
		"north"     : "/open/clan/nine-sky-dragon/room/room40",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
