inherit ROOM;
void create() {
	set( "short", "阿華田三家" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
	]) );
	set( "owner", "ovaltine" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room164",
	]) );
	set( "build", 10892 );
	set( "light_up", 1 );
	set( "long", @LONG
阿華田三家-----------------------
阿華田三家---------------------------
阿華田三家---------------------------
阿華田三家---------------------------
阿華田三家---------------------------
阿華田三家---------------------------


LONG);
	setup();
	replace_program(ROOM);
}
