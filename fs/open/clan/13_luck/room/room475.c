inherit ROOM;
void create() {
	set( "short", "福林酒樓" );
	set( "object", ([
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file2"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10003 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room478",
		"up"        : "/open/clan/13_luck/room/room489",
	]) );
	set( "long", @LONG

    這裡便是邑陽馳名遠近的福林酒樓。福林酒樓是一家近百年老店，
傳到現在的這位老掌櫃已經是第三代，如果你是初到此地的外地人，不
妨和他攀攀交情，酒樓一樓多半是縣城裡熟客人，東北邊有一道方梯通
往樓上雅座，往東則可以出大街。

LONG);
	setup();
	replace_program(ROOM);
}
