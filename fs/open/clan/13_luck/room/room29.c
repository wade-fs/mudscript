inherit ROOM;
void create() {
	set( "short", "吉祥水道入口" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 18,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
	]) );
	set( "build", 14243 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room28.c",
		"out"       : "/open/clan/13_luck/room/room30",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    當你一來到就覺的這裡非常喧囂，你放眼望去有忙忙碌碌的人們正
在水道邊忙碌的裝卸貨物，這樣熱鬧的景象映入眼簾，讓你深深覺得十
三吉祥是個繁榮的地方，如果你想通過水道，你可以問問船家，他們會
很樂意的載你前往的。

LONG);
	setup();
	replace_program(ROOM);
}
