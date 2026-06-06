inherit ROOM;
void create() {
	set( "short", "龍鱗房" );
	set( "object", ([
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
	]) );
	set( "owner", "soul" );
	set( "build", 13521 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room37",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
