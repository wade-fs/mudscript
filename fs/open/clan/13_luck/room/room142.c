inherit ROOM;
void create() {
	set( "short", "聚氣室" );
	set( "object", ([
		"amount3"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/daemon/class/fighter/figring",
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file3"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount1"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"file2"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "light_up", 1 );
	set( "build", 10131 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room140.c",
		"north"     : "/open/clan/13_luck/room/room170.c",
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
