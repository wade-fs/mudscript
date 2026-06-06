inherit ROOM;
void create() {
	set( "short", "七彩陣之橙陣" );
	set( "object", ([
		"file3"    : "/open/capital/obj/4-2",
		"amount5"  : 553,
		"file2"    : "/obj/gift/shenliwan",
		"amount4"  : 2600,
		"file4"    : "/open/killer/obj/s_pill",
		"amount3"  : 1,
		"file7"    : "/open/snow/obj/snow_token",
		"amount9"  : 1,
		"file6"    : "/open/mon/obj/mon-pill",
		"file9"    : "/obj/gift/unknowdan",
		"file8"    : "/open/killer/obj/bellstar",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/open/snow/obj/stone",
		"amount7"  : 1,
		"amount8"  : 6803,
		"amount10" : 1,
		"file5"    : "/open/mon/obj/mon-pill",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount6"  : 538,
	]) );
	set( "build", 10048 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room341.c",
		"north"     : "/open/clan/13_luck/room/room687",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『橙』陣，眼前所見的景物都是橙色
，就如單色的世界一般。陣中央有根『橙水晶』，正是
通過此陣的必要之物，也是七彩陣的第二根水晶。因此，
你必須拿到這根水晶，打開陣門，才能繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
