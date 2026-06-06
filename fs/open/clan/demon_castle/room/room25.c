inherit ROOM;
void create() {
	set( "short", "天之風" );
	set( "object", ([
		"amount6"  : 1,
		"file6"    : "/open/ping/obj/gold_hand",
	]) );
	set( "owner", "mory" );
	set( "build", 10011 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room24",
		"west"      : "/open/clan/demon_castle/room/room20",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
