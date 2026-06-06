inherit ROOM;
void create() {
	set( "short", "世間風道" );
	set( "object", ([
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
	]) );
	set( "build", 10998 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room300.c",
		"south"     : "/open/clan/13_luck/room/room319",
		"east"      : "/open/clan/13_luck/room/room277.c",
		"north"     : "/open/clan/13_luck/room/room272.c",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五候道，此道為風
道，用來比喻十三吉祥的威力，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
