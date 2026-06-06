inherit ROOM;
void create() {
	set( "short", "禁地-神兵室" );
	set( "owner", "zeros" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"amount4"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/ghost-hole/obj/fire-spirit",
		"file3"    : "/open/ghost-hole/obj/fire-spirit",
		"amount1"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount2"  : 1,
		"file1"    : "/open/capital/obj/book",
	]) );
	set( "build", 10299 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room238",
	]) );
	set( "long", @LONG

歷代宮主都會打隱居在止的江湖人士的配兵做一番評鑑,如果是稀世的神
兵就會將止神兵收藏在這裡,以免後人遇到重大危機時無神兵利器可以抗
敵,止時你一眼望看到排在兵架上的首三把神兵分別是自遠古時代三界勇
者所遺留下來的配兵,天勇者龍龍(THIEF)-終神秘器 地勇者厲若海(TKC)-
聖刀無刃 水勇者蘇菲亞(SUFAYA)-魔神器 幻空,原來皆是收藏在止.

LONG);
	setup();
	replace_program(ROOM);
}
