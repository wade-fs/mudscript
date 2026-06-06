inherit ROOM;
void create() {
	set( "short", "青龍盤天" );
	set( "owner", "mad" );
	set( "object", ([
		"file3"    : "/open/ping/obj/gold_hand",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/ping/obj/gold_hand",
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/ping/obj/chilin_legging",
		"file8"    : "/daemon/class/fighter/armband",
		"amount7"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount2"  : 3,
		"file5"    : "/open/ping/obj/chilin_legging",
		"file7"    : "/open/badman/obj/evil_claw",
	]) );
	set( "build", 13842 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room18.c",
		"up"        : "/open/clan/13_luck/room/room20",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    經過了青龍殿之後看到了青色的階梯盤旋向上延伸，宛如一條青龍
往天際直飛而去，看到階梯入口有士兵把守著就覺得通往上面的地方是
個重要之地，守衛每一個人都嚴肅的站崗著，除非有幫主給的通行證，
不然想硬闖你就準備血濺當場吧。

LONG);
	setup();
	replace_program(ROOM);
}
