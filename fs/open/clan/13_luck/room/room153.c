inherit ROOM;
void create() {
	set( "short", "吉祥林道" );
	set( "owner", "tomorrow" );
	set( "object", ([
		"file7"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file1"    : "/open/magic-manor/obj/lunar-heart",
	]) );
	set( "outdoors", "/open/clan/13_luck" );
	set( "build", 10149 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room152",
		"west"      : "/open/clan/13_luck/room/room154",
	]) );
	set( "long", @LONG

　　當你向前遠望時，一座廣大的森林就在不遠前，被一大片白霧籠
照的森林，立即引起你的好奇心，想前往一探究竟，可是冒然前往是
極危險的事，因此向人四處打探，終於得知原來前方正是惡名昭彰的
霧之林，有進無出。

LONG);
	setup();
	replace_program(ROOM);
}
