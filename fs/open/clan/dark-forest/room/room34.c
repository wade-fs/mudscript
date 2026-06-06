inherit ROOM;
void create() {
	set( "short", "魔龍麟房" );
	set( "object", ([
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10056 );
	set( "owner", "mika" );
	set( "exits", ([
		"east"      : "/open/clan/dark-forest/room/room36",
	]) );
	set( "long", @LONG
一號左邊一號左邊一號左邊一號左邊一號左邊一號左邊一號左邊一號左邊一號左邊一號左邊
一號左邊一號左邊一號左邊一號左邊一號左邊
一號左邊一號左邊一號左邊一號左邊一號左邊
一號左邊一號左邊一號左邊一號左邊一號左邊
一號左邊一號左邊一號左邊一號左邊一號左邊
一號左邊一號左邊一號左邊一號左邊一號左邊


LONG);
	setup();
	replace_program(ROOM);
}
