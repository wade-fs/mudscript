inherit ROOM;
void create() {
	set( "short", "凌雲亭" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10325 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room566",
		"north"     : "/open/clan/13_luck/room/room564",
	]) );
	set( "long", @LONG
一座雕工相當精緻的涼亭，只見亭頂邊的牌板刻著『凌雲亭』
三個豔金字，前面的兩根朱紅色柱子有一闕詩(poem)，寫的氣勢豪
放。亭四周的奇花豔草及佳木白石更襯出此亭的意境，不食人間煙
火。
LONG);
	setup();
	replace_program(ROOM);
}
