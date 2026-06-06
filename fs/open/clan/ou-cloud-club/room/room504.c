inherit ROOM;
void create() {
	set( "short", "剛強的臥房" );
	set( "object", ([
		"amount4"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/obj/stone/suipian",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10752 );
	set( "light_up", 1 );
	set( "owner", "roboii" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room505",
	]) );
	set( "long", @LONG
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
床床床床床床床床床床床床床床
LONG);
	setup();
	replace_program(ROOM);
}
