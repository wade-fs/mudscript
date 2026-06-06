inherit ROOM;
void create() {
	set( "short", "詠泉亭" );
	set( "build", 11420 );
	set( "object", ([
		"file9"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount8"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/main/obj/dragon-moon",
		"file2"    : "/open/magic-manor/obj/lunar-heart",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount10" : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room154",
		"west"      : "/open/clan/13_luck/room/hall.c",
	]) );
	set( "long", @LONG

    在詠泉亭裡只有一張石桌和幾張石椅，看起來好像有些歷史了當你
向前遠望時，你感到非常高興，因為目的地即將到達，而石桌上放著一
副棋子，正等著棋友下他一盤，從這裡往外看去可以將柳月泉的風光盡
收眼底，這裡也是讓人最喜歡的地方。

LONG);
	setup();
	replace_program(ROOM);
}
