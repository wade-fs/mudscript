inherit ROOM;
void create() {
	set( "short", "雷峰試煉塔四樓" );
	set( "build", 10053 );
	set( "exits", ([
		"north"     : "/open/clan/free-zone/room/room51",
		"down"      : "/open/clan/free-zone/room/room48",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
