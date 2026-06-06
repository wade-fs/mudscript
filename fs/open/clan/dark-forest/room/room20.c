inherit ROOM;
void create() {
	set( "short", "G‧S" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/obj/gift/lingzhi",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10041 );
	set( "exits", ([
		"down"      : "/open/clan/dark-forest/room/room19",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
