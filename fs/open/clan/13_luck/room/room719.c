inherit ROOM;
void create() {
	set( "short", "四樓southwest" );
	set( "owner", "zmud" );
	set( "build", 10018 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room715",
		"north"     : "/open/clan/13_luck/room/room714",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
