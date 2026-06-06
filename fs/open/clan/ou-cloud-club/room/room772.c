inherit ROOM;
void create() {
	set( "short", "月神放牧的草原" );
	set( "object", ([
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount4"  : 1,
		"amount2"  : 99,
		"amount10" : 1,
		"amount9"  : 1,
		"file7"    : "/open/capital/obj/4-1",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 358,
		"amount1"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file3"    : "/obj/gift/shenliwan",
		"file1"    : "/open/capital/obj/4-2",
		"amount6"  : 1,
		"file8"    : "/open/killer/obj/atman_pill",
		"amount7"  : 1,
		"amount8"  : 427,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "build", 10096 );
	set( "owner", "nana" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room738",
	]) );
	set( "long", @LONG

此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。
此地初建，空無一物。

LONG);
	setup();
	replace_program(ROOM);
}
