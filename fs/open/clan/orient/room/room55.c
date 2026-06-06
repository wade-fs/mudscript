inherit ROOM;
void create() {
	set( "short", "$HIC$青龍長廊Ⅰ$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room56",
		"east"      : "/open/clan/orient/room/room6.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
