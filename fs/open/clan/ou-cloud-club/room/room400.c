inherit ROOM;
void create() {
	set( "short", "$HIB$龍王道$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 11155 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room401.c",
		"south"     : "/open/clan/ou-cloud-club/room/room149.c",
		"north"     : "/open/clan/ou-cloud-club/room/room152.c",
		"east"      : "/open/clan/ou-cloud-club/room/room450.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    這一道迴廊的建材據說是從遠古龍王『巴哈姆特』上的鱗片
用煉獄之火以及脈動之血加工後所製造出來的，走在這裡雖然會
覺得有一股莫名的壓力籠罩著你，但遠古龍王所蘊藏的能量也讓
你覺得全身上下充滿了蓄勢待發的戰力。

北邊是稅官(officer)的稅捐處，南邊是韋小寶(weishoubow)的小寶神龍教

LONG);
	setup();
	replace_program(ROOM);
}
