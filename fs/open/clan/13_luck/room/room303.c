inherit ROOM;
void create() {
	set( "short", "世間水道" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
	]) );
	set( "build", 10206 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room304.c",
		"south"     : "/open/clan/13_luck/room/room315",
		"east"      : "/open/clan/13_luck/room/room302.c",
		"north"     : "/open/clan/13_luck/room/room264.c",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五行道，此道為水
道，用來比喻十三吉祥的防禦，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
