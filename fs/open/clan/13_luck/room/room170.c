inherit ROOM;
void create() {
	set( "short", "曇花聚氣室" );
	set( "object", ([
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"amount10" : 1,
		"file2"    : "/open/wu/obj/armband",
		"file9"    : "/open/tendo/obj/chaosbelt",
		"amount8"  : 1,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"file4"    : "/open/wu/obj/figring",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount6"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "owner", "djlh" );
	set( "build", 10146 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room142",
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
