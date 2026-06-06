inherit ROOM;
void create() {
	set( "short", "三樓southwest" );
	set( "owner", "zmud" );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room709",
		"north"     : "/open/clan/13_luck/room/room707",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
