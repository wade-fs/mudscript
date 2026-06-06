inherit ROOM;
void create() {
	set( "short", "$HIC$青龍長廊Ⅲ$NOR$" );
	set( "owner", "pach" );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room56",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
