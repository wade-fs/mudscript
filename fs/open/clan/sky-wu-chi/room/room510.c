inherit ROOM;
void create() {
	set( "short", "sweat用" );
	set( "owner", "minidragon" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
	]) );
	set( "build", 7607 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room314",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
