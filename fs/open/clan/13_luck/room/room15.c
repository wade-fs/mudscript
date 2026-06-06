inherit ROOM;
void create() {
	set( "short", "朱雀堂口" );
	set( "owner", "mad" );
	set( "object", ([
		"amount2"  : 9,
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"file1"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount9"  : 1,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"amount6"  : 1,
		"file3"    : "/open/snow/obj/figring",
		"amount5"  : 1,
	]) );
	set( "build", 10377 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room14",
		"west"      : "/open/clan/13_luck/room/room16.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    終於來到朱雀堂的外面，在門邊的石柱雕著鳳凰，鳳凰身上披著紅
衫，聽說此紅衫是花了數以百年的時間，請十三吉祥的畫工師傅一筆一
畫的慢慢加上的，使整個鳳凰有如浴火重生永不消失，這隻鳳凰也是十
三吉祥的精神象徵。

LONG);
	setup();
	replace_program(ROOM);
}
