inherit ROOM;
void create() {
	set( "short", "四樓south" );
	set( "owner", "zmud" );
	set( "build", 10042 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room721",
		"north"     : "/open/clan/13_luck/room/room660.c",
		"west"      : "/open/clan/13_luck/room/room719.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
