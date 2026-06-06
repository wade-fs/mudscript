inherit ROOM;
void create() {
	set( "short", "五轉聚靈珠庫" );
	set( "owner", "apple" );
	set( "build", 10182 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/room21",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
