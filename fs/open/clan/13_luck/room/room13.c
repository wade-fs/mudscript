inherit ROOM;
void create() {
	set( "short", "青龍殿迴廊" );
	set( "owner", "mad" );
	set( "object", ([
		"amount2"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file7"    : "/open/ping/obj/chilin_legging",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file2"    : "/daemon/class/fighter/armband",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file10"   : "/open/mogi/castle/obj/seven2-dark-head",
		"file8"    : "/open/ping/obj/iceger",
		"amount1"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file5"    : "/open/prayer/obj/boris-cloth",
		"file3"    : "/open/ping/obj/gold_hand",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10119 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room697",
		"west"      : "/open/clan/13_luck/room/room12.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在往白虎堂的路上看到美麗的花種植在路旁的花園裡，花園裡有假
山流水是一個費盡心思所布置的地方，一切只為了只為了讓青龍殿變的
更美麗，妳在往西邊走著走著，過了不久聽到不遠處傳來喧嘩聲，可見
『白虎堂』快到了。

LONG);
	setup();
	replace_program(ROOM);
}
