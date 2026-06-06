inherit ROOM;
void create() {
	set( "short", "東長廊" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
	]) );
	set( "build", 10108 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room515",
		"south"     : "/open/clan/13_luck/room/room513",
	]) );
	set( "long", @LONG
這裡是北長廊的盡頭轉角，只見你面前的壁上掛著一幅詩畫，而雕
工精細的檀木桌上擺放了一只唐花彩瓷，裡頭的蘭花更散發出清淡的香
味，陽光從壁上方的方格木窗灑落，使你有一種清爽的感覺。跟四周的
強烈殺氣成了一個強烈的對比，仿佛來到了帶著天堂的環境，但是是地
獄的地方。
LONG);
	setup();
	replace_program(ROOM);
}
