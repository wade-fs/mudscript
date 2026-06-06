inherit ROOM;
void create() {
	set( "short", "$HIC$奇犽‧揍敵客$HIW$ソ$HIR$念能力$HIY$修習室$NOR$" );
	set( "owner", "killua" );
	set( "object", ([
		"amount2"  : 519,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount4"  : 179,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 3136,
		"file5"    : "/open/killer/obj/atman_pill",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 33,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 197,
		"amount6"  : 28,
		"amount3"  : 304,
		"amount8"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 1,
	]) );
	set( "build", 10100 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room719",
		"east"      : "/open/clan/ou-cloud-club/room/room572.c",
		"south"     : "/open/clan/ou-cloud-club/room/room415.c",
		"north"     : "/open/clan/ou-cloud-club/room/room551.c",
		"west"      : "/open/clan/ou-cloud-club/room/room573",
	]) );
	set( "long", @LONG

    這裡是奇犽‧揍敵客ソ念能力修習室，在還沒成為獵人之前
，奇犽常常在這裡練習揍敵客家暗殺的技巧，考上獵人執照後就
常常在這裡修習念能力。

    念能力，就是能自由操縱從體內發出的氣的能力。氣的強弱
與自身的資質，或戰鬥時的精神狀況，有絕對的關係。一般分為
四大行：「纏」「絕」「練」「發」。依照個人資質的不同，可
習得的念能力亦不同：強化系、變化系、具現化系、放出系、操
作系、特質系。可以利用水見式探知自己所屬之念系。

LONG);
	setup();
	replace_program(ROOM);
}
