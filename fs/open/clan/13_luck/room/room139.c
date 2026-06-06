inherit ROOM;
void create() {
	set( "short", "大廳" );
	set( "object", ([
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room344.c",
		"south"     : "/open/clan/13_luck/room/room355",
		"west"      : "/open/clan/13_luck/room/room172.c",
		"out"       : "/open/clan/13_luck/room/room138.c",
		"north"     : "/open/clan/13_luck/room/room174.c",
	]) );
	set( "long", @LONG

　　一踏進大廳，正中央的壁上掛著一副「　九　天　遊　龍　」的
圖晝，龍遊九天是如此的威風凜凜，不可一世。而更令人大為驚訝的
是，這幅畫並非用一般筆墨繪畫而成，而是取自黃金甲龍身上的鱗片
所繪製而成的，其價值更勝大門上的牌匾。

LONG);
	setup();
	replace_program(ROOM);
}
