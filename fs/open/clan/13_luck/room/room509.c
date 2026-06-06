inherit ROOM;
void create() {
	set( "short", "天璣堂修武場" );
	set( "object", ([
		"file8"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount10" : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "owner", "aaabc" );
	set( "build", 12158 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room510",
	]) );
	set( "long", @LONG
在這裡的每一個弟子都散發出一陣陣的殺氣，這裡的練習弟子武功
都已經有一些底子，只見他們舞的一手好功夫，也有弟子在練習拳法，
只見一套拳打的虎虎生風，有些弟子在練習腿法，看來他們不光是練習
兵器，更有拳腳上的修養，使你忍不住要向他們討教個兩三招，試試自
己的本領。
LONG);
	setup();
	replace_program(ROOM);
}
