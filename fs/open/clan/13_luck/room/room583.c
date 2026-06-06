inherit ROOM;
void create() {
	set( "short", "火靈焰扇" );
	set( "object", ([
		"amount10" : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/firedancer/npc/eq/r_pants",
		"amount3"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_boots",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/wu/obj/armband",
		"amount8"  : 1,
		"file1"    : "/open/wu/obj/figring",
		"file6"    : "/open/capital/guard/gring",
		"file5"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "basaka" );
	set( "build", 10057 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room584.c",
	]) );
	set( "long", @LONG
要勇闖聚靈山莊，必先收集滿五塔主武器，分別是金塔主的金色靈
刀，木塔主的綠色靈劍，水塔主的水色絲帶，火塔主的火靈焰扇，和土
塔主的土色靈爪而在這個房間正是專門存放五塔主武器中的火靈扇，焰
扇形狀就像火焰一般，而且相當的熾熱，據說裡面封印著一隻火鳳凰，
會隨機出現攻擊敵人，是火塔主的得意兵器。

LONG);
	setup();
	replace_program(ROOM);
}
