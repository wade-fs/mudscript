inherit ROOM;
void create() {
	set( "short", "$HIC$青龍長廊Ⅱ$NOR$" );
	set( "owner", "pach" );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room57",
		"east"      : "/open/clan/orient/room/room55.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
