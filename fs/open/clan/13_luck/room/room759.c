inherit ROOM;
void create() {
	set( "short", "小小邦的電腦書房" );
	set( "object", ([
		"file9"    : "/open/tendo/obj/chaosbelt",
		"amount9"  : 1,
		"file3"    : "/open/firedancer/npc/eq/r_hands",
		"amount10" : 1,
		"file7"    : "/open/firedancer/npc/eq/r_pants",
		"amount5"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/tendo/obj/chaosbelt",
		"file1"    : "/open/common/obj/liz_meat",
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10020 );
	set( "owner", "yken" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room758",
	]) );
	set( "long", @LONG
四面牆壁上擺滿了各式各樣的電腦書籍，算算小小邦碰電腦也已經有十
戎H上了，從最早的8086大片軟碟開始，到現在最新的core 2 duo，甚
至是4 core，小小邦永遠也沒有想到，小時候的興趣，可以在未來的工
作發揮這麼大的影響，也許有天，小小邦在MUD的經驗，也會有不可思議
的影響呢。

LONG);
	setup();
	replace_program(ROOM);
}
