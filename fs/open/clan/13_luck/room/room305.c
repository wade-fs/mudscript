inherit ROOM;
void create() {
	set( "short", "世間木道" );
	set( "object", ([
		"amount9"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
	]) );
	set( "build", 10524 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room306.c",
		"south"     : "/open/clan/13_luck/room/room317",
		"east"      : "/open/clan/13_luck/room/room304.c",
		"north"     : "/open/clan/13_luck/room/room274.c",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五行道，此道為木
道，用來比喻十三吉祥的防禦，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
