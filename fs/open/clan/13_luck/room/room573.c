inherit ROOM;
void create() {
	set( "short", "北長廊" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room574",
		"up"        : "/open/clan/13_luck/room/room572",
	]) );
	set( "long", @LONG
這裡是東長廊的盡頭轉角，只見你面前的壁上掛著一幅詩畫，
而雕工精細的檀木桌上擺放了一只唐花彩瓷，裡頭的蘭花更散發出
清淡的香味，陽光從壁上方的方格木窗灑落，使你有一種清爽的感
覺。往樓梯走上去便是招待用的客房了。
LONG);
	setup();
	replace_program(ROOM);
}
