inherit ROOM;
void create() {
	set( "short", "老大的酒池肉林" );
	set( "object", ([
		"file2"    : "/obj/stone/suipian",
		"amount3"  : 29,
		"file3"    : "/open/mon/obj/mon-pill",
		"amount2"  : 1,
		"file1"    : "/obj/stone/powder",
		"amount1"  : 3,
	]) );
	set( "owner", "uesz" );
	set( "light_up", 1 );
	set( "build", 11310 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room116",
		"west"      : "/open/clan/hell/room/room118.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
