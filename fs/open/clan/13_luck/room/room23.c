inherit ROOM;
void create() {
	set( "short", "齊天道" );
	set( "owner", "mad" );
	set( "object", ([
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/prayer/obj/boris-boots",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/soldier/obj/snake",
		"amount10" : 1,
		"file5"    : "/open/gsword/obj1/kring",
		"file4"    : "/open/port/obj/wolf_ring",
		"amount1"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/dancer/obj/yuawaist",
		"amount6"  : 1,
		"file2"    : "/open/ping/obj/gold_hand",
		"amount2"  : 1,
		"file9"    : "/u/b/babe/cloud",
		"file1"    : "/open/ping/obj/ring-2",
		"amount3"  : 1,
	]) );
	set( "build", 14475 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room24",
		"south"     : "/open/clan/13_luck/room/room22.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在齊天道地上鋪著深藍色的地毯，真的有與天同高的感覺，在地毯
的兩邊站了守衛，守衛顫顫驚驚的守著齊天道，深怕外人闖入其實齊天
道也可以稱為掛天橋，因為你從皇城由下往上看會覺得那是掛在雲端上
的天橋。

LONG);
	setup();
	replace_program(ROOM);
}
