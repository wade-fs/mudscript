inherit ROOM;
void create() {
	set( "short", "世間雨道" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount10" : 1,
		"amount4"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount9"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "build", 13695 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room298.c",
		"south"     : "/open/clan/13_luck/room/room321",
		"east"      : "/open/clan/13_luck/room/room300.c",
		"north"     : "/open/clan/13_luck/room/room270",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五候道，此道為雨
道，用來比喻十三吉祥的威力，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
