inherit ROOM;
void create() {
	set( "short", "葵花聚氣室" );
	set( "object", ([
		"amount3"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/tendo/obj/chaosbelt",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/gsword/obj/may_ring",
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room142",
		"south"     : "/open/clan/13_luck/room/room136.c",
	]) );
	set( "long", @LONG

　　這裡是十三吉祥的葵花聚氣室，其所存放的裝備，是幫裡長老們
，打敗千年樹精舞風揚、瀧山任正晴、魔刀莫無愁、浪跡天涯郭襄、
魔界羅煞女等武林高手，費盡千辛萬苦才有這些成果，為的只是要讓
幫眾們早日衝破內功瓶頸，達到武學更顛峰。

LONG);
	setup();
	replace_program(ROOM);
}
