inherit ROOM;
void create() {
	set( "short", "煮豆屋" );
	set( "object", ([
		"file9"    : "/open/capital/obj/4-4",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount8"  : 100,
		"amount4"  : 100,
		"amount5"  : 100,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 100,
		"amount3"  : 100,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 100,
		"file1"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 100,
		"file7"    : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 104,
	]) );
	set( "build", 10043 );
	set( "owner", "bior" );
	set( "exits", ([
		"east"      : "/open/clan/nine-sky-dragon/room/room39.c",
		"south"     : "/open/clan/nine-sky-dragon/room/room42",
		"out"       : "/open/clan/nine-sky-dragon/room/room41.c",
		"down"      : "/open/clan/nine-sky-dragon/room/hall.c",
		"north"     : "/open/clan/nine-sky-dragon/room/room43.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
