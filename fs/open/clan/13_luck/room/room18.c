inherit ROOM;
void create() {
	set( "short", "青龍殿" );
	set( "owner", "mad" );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file10"   : "/daemon/class/fighter/figring",
		"amount7"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
	]) );
	set( "build", 10156 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room697",
		"north"     : "/open/clan/13_luck/room/room19.c",
	]) );
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
