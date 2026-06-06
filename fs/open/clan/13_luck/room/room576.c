inherit ROOM;
void create() {
	set( "short", "前廳" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount10" : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10447 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room577.c",
		"north"     : "/open/clan/13_luck/room/room569",
		"east"      : "/open/clan/13_luck/room/room575.c",
	]) );
	set( "long", @LONG
    你被這裡的一股莫名的氣勢震住了，它簡直就像一座宮殿般的
富麗堂皇，而其華麗的裝飾下卻也不失沉穩內斂，微微檀香傳來，
令你的心情不自覺的平靜和緩，與世無爭的感覺油然而生。前方就
是大廳了，你禁不住的緊張，深呼一口氣，向前走去。
LONG);
	setup();
	replace_program(ROOM);
}
