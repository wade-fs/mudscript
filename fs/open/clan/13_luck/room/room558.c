inherit ROOM;
void create() {
	set( "short", "你會選擇什麼呢?(3)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file6"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file10"   : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/xisuidan",
		"amount6"  : 1,
	]) );
	set( "build", 10027 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room560",
	]) );
	set( "long", @LONG
被人群推塞擁擠，因此不得不向前，每一步，或多或少，
都有些勉強與不稅。如此循環迴轉，
於是衍成了洞知未來的不可不為。有此繞口了，
其實我的意思正如標題：
假使有一件事，不做會遺憾，做了會後悔，你會如何？
假使有一個人，愛了會後悔，不愛會遺憾，你會愛嗎？
似乎，選擇就是這麼一回事。豈止選擇，人生也或是如此吧。
LONG);
	setup();
	replace_program(ROOM);
}
