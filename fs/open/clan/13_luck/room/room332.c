inherit ROOM;
void create() {
	set( "short", "神風聖堂" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 12369 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room334",
		"enter"     : "/open/clan/13_luck/room/room331",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    終於來到了神風聖堂，眼前站著一位高人，他並不是天下會的
神風堂主--->聶風。他輕飄飄的身影，輕功已經達到神而明之的超
凡境界，堅定的目光，透露出剛強不拔之氣而是打敗聶風的風魔小
浪女，而小浪女喜愛人才，留聶風下來教導武學，也希望席日聶風
可以戰勝小浪女。


LONG);
	setup();
	replace_program(ROOM);
}
