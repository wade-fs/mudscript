inherit ROOM;
void create() {
	set( "short", "星光流洩的原野" );
	set( "object", ([
		"file5"    : "/open/mon/obj/mon-pill",
		"amount9"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 1,
		"file2"    : "/open/capital/guard/gring",
		"amount1"  : 600,
		"amount3"  : 143,
		"file7"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file4"    : "/obj/gift/shenliwan",
		"amount5"  : 355,
		"amount8"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10207 );
	set( "owner", "narnia" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room738",
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
