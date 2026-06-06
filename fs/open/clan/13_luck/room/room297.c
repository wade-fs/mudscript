inherit ROOM;
void create() {
	set( "short", "世間電道" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount3"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount6"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 11130 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room323",
		"east"      : "/open/clan/13_luck/room/room298.c",
		"north"     : "/open/clan/13_luck/room/room268",
	]) );
	set( "long", @LONG

    滄桑歲月，世間常變，來到這條十三吉祥的世間五候道，此道為電
道，用來比喻十三吉祥的後勁，而此道上面都放著給幫眾的防具與武器
，而適用對象為，沒時間打防具跟武器的幫眾，與新進幫眾沒能力打防
具與沒自己的房間可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
