inherit ROOM;
void create() {
	set( "short", "奇幻之門" );
	set( "object", ([
		"file8"    : "/open/magic-manor/obj/golden-ball",
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/obj/water-ball",
		"amount5"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/water-ball",
		"amount1"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/fire-ball",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/obj/soil-ball",
		"file9"    : "/open/magic-manor/obj/fire-ball",
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 13344 );
	set( "exits", ([
		"aoi"       : "/open/clan/ou-cloud-club/room/room550",
		"out"       : "/open/clan/ou-cloud-club/room/room426.c",
		"clair"     : "/open/clan/ou-cloud-club/room/room535",
		"aerith"    : "/open/clan/ou-cloud-club/room/room534.c",
	]) );
	set( "long", @LONG
走入這裡，你發現這裡是ctx的後院，而這邊又建滿了一棟
棟的別院，仔細一看才發現原來這些別院都是ctx的其他char所
住的地方，可別小看這些小小的別院喔，裡面可是三房兩廳的,
該有的都有喔，可說是麻雀雖小五臟俱全的。

LONG);
	setup();
	replace_program(ROOM);
}
