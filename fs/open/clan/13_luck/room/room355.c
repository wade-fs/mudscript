inherit ROOM;
void create() {
	set( "short", "南偏門" );
	set( "object", ([
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10119 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room356",
		"north"     : "/open/clan/13_luck/room/room139.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    黃金甲龍原本是整座炎龍谷的守護者，上古時代的魔獸，但因為
身上似乎有著什麼秘密，被鄭柳兩家的人合力擒捕，後來鄭雨橋出賣
了柳家，將它私藏，才有這一段恩怨情仇；黃金甲龍被藏於炎龍谷的
最深處，被玄鐵鎖給鎖著，有時還可以聽到它的怒吼～～

LONG);
	setup();
	replace_program(ROOM);
}
