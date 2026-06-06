inherit ROOM;
void create() {
	set( "short", "狂影登天樓" );
	set( "owner", "mill" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
	]) );
	set( "build", 10087 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room130",
	]) );
	set( "long", @LONG

   這裡便是十三奇景之一的天之樓閣，放眼望去四周盡是十三地盤
，往前一看，前方正立著三大層樓閣，樓閣四周淡淡放出一股鬥氣，
遠遠望去，三大樓各各雕著三個字，{望月樓} {煙雨樓} {鳳凰樓}，
這三大樓果然如意想中是十三鬥士休息處，難怪有股傲然氣勢。

LONG);
	setup();
	replace_program(ROOM);
}
