inherit ROOM;
void create() {
	set( "short", "紅龍宮" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "kitty" );
	set( "build", 27228 );
	set( "exits", ([
		"west"      : "/open/clan/free-zone/room/room52",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
