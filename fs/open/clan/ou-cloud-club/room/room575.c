inherit ROOM;
void create() {
	set( "short", "新區域J-E" );
	set( "owner", "snowy" );
	set( "object", ([
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
		"amount10" : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/unknowdan",
		"file7"    : "/open/capital/obj/4-2",
		"amount4"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
	]) );
	set( "build", 10406 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room574",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
