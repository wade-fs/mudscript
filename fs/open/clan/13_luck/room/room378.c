inherit ROOM;
void create() {
	set( "short", "十三劍堂" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room399",
		"east"      : "/open/clan/13_luck/room/room377.c",
	]) );
	set( "long", @LONG

    眼前映入兩扇精鋼所做的大門，純樸而不過度花俏給人一股穩重的感
覺。大門左右各有一名劍堂弟子奉命把守這裡，若無身份上的確認他們可
是會阻殺你的ㄡ。所以未取得浪子正式認可之前最好不要隨便踏入這裡。
再往東走就可見到十三劍堂的現任堂主，你若需知道天山劍邪的下落就得
要尋問他才知道。

LONG);
	setup();
	replace_program(ROOM);
}
