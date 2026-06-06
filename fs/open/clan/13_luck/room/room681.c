inherit ROOM;
void create() {
	set( "short", "武神居小徑" );
	set( "object", ([
		"file9"    : "/open/capital/obj/4-2",
		"amount1"  : 1,
		"amount8"  : 414,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file4"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10052 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room682.c",
		"north"     : "/open/clan/13_luck/room/room680",
	]) );
	set( "long", @LONG

    前方就是一般所到不了的武神居，平凡的草蓆屋子住
著不平凡的大人物。為了見上武神一面，你不遠千里迢迢
，通過七彩陣迷陣的試煉，才來到『武神居』。這段路雖
然漫長，但能得到武神的當面指導，在武學上一定受益非
淺。

LONG);
	setup();
	replace_program(ROOM);
}
