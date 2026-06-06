inherit ROOM;
void create() {
	set( "short", "小叡愛我" );
	set( "object", ([
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount7"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"file1"    : "/open/capital/obj/blade2",
	]) );
	set( "build", 10588 );
	set( "owner", "dklove" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room634",
	]) );
	set( "long", @LONG
小叡愛我 小叡愛我 小叡愛我 小叡愛我 小叡愛我

小叡愛我 小叡愛我 小叡愛我 小叡愛我 小叡愛我

小叡愛我 小叡愛我 小叡愛我 小叡愛我 小叡愛我

小叡愛我 小叡愛我 小叡愛我 小叡愛我 小叡愛我

小叡愛我 小叡愛我 小叡愛我 小叡愛我 小叡愛我
LONG);
	setup();
	replace_program(ROOM);
}
