inherit ROOM;
void create() {
	set( "short", "小南家中廳" );
	set( "owner", "son" );
	set( "object", ([
		"file8"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount9"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/ping/questsfan/obj/diamond_hands",
		"file4"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount3"  : 1,
		"file9"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount10" : 1,
		"amount1"  : 1,
		"file5"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount6"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount7"  : 1,
		"file10"   : "/open/ping/questsfan/obj/diamond_hairpin",
		"file7"    : "/open/ping/questsfan/obj/diamond_legging",
		"file1"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10719 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room67.c",
		"east"      : "/open/clan/13_luck/room/room107.c",
		"west"      : "/open/clan/13_luck/room/room285",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    來到這有如人間的另一個世外桃源，完全沒有任何壓力，這四周
充滿了祥和。溫暖的氣氛，四周圍充滿了迷霧，你不禁深深的吸了一
口氣，吸入體內後忽然感覺整個人變得更有精神與活力，就找了一個
地方坐下運行內力，發覺自己的內力修為增進了不少。


妳發覺藍色的迷霧圍繞正在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
