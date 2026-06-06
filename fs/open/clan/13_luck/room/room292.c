inherit ROOM;
void create() {
	set( "short", "一分鐘待命班" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10473 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room284",
	]) );
	set( "long", @LONG
一分鐘待命班..為應付大門的緊急狀況而設立的..除了可以
驅逐敵人還可以消防與檢毒..大多要求八秒之內要帶上防毒面具
..一分鐘內不管你在任何地方..集合時都要到..而且要全副武裝
建制武器跟設備..都要帶齊..而大門的緊急狀況就要看他們了..
人過多就要連洛警衛排或戰備連出動了..
LONG);
	setup();
	replace_program(ROOM);
}
