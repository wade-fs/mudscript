inherit ROOM;
void create() {
	set( "short", "hild預定地Ⅰ" );
	set( "owner", "working" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
	]) );
	set( "build", 10695 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room69.c",
		"south"     : "/open/clan/orient/room/room67",
		"north"     : "/open/clan/orient/room/room68.c",
		"west"      : "/open/clan/orient/room/room26.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
