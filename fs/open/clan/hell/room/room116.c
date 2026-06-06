inherit ROOM;
void create() {
	set( "short", "老大老大我最愛" );
	set( "owner", "uesz" );
	set( "outdoors", "/open/clan/hell" );
	set( "object", ([
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/obj/wood-ball",
	]) );
	set( "light_up", 1 );
	set( "build", 11526 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room117.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
