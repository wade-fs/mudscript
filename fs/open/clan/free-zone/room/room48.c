inherit ROOM;
void create() {
	set( "short", "雷峰試煉塔三樓" );
	set( "build", 12336 );
	set( "exits", ([
		"up"        : "/open/clan/free-zone/room/room50",
		"north"     : "/open/clan/free-zone/room/room49",
		"down"      : "/open/clan/free-zone/room/room46",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
