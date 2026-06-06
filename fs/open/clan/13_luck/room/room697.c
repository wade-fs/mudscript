inherit ROOM;
void create() {
	set( "short", "青龍殿" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room16.c",
		"west"      : "/open/clan/13_luck/room/room13.c",
		"north"     : "/open/clan/13_luck/room/room18",
		"out"       : "/open/clan/13_luck/room/room11",
	]) );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/snow/obj/figring",
		"file4"    : "/open/gsword/obj/dragon-sword",
		"amount5"  : 1,
	]) );
	set( "build", 10219 );
	set( "light_up", 1 );
	set( "long", @LONG

    走了一會覺得青龍殿快到了盡頭，以為會看到大殿堂，但是好像沒
有看到任何東西，沒多久看到前方好像有寬廣的空地，空地上有向上爬
伸的青環不知道是什麼，所以你馬上快速的前去，只見到青環一直向上
攀升似乎看不到進頭。

LONG);
	setup();
	replace_program(ROOM);
}
