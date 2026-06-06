inherit ROOM;
void create() {
	set( "short", "四樓north" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10030 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room660.c",
		"east"      : "/open/clan/13_luck/room/room720",
		"west"      : "/open/clan/13_luck/room/room718.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
