inherit ROOM;
void create() {
	set( "short", "暫存區" );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room162.c",
		"north"     : "/open/clan/time-limit/room/hall",
	]) );
	set( "owner", "mary" );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
