inherit ROOM;
void create() {
	set( "short", "三樓west" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10032 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room712",
		"east"      : "/open/clan/13_luck/room/room661.c",
		"north"     : "/open/clan/13_luck/room/room711.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
