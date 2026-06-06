inherit ROOM;
void create() {
	set( "short", "ζ小南家走廊ζ" );
	set( "owner", "son" );
	set( "build", 10007 );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room17",
		"south"     : "/open/clan/demon_castle/room/room18.c",
		"west"      : "/open/clan/demon_castle/room/room21.c",
	]) );
	set( "long", @LONG

    來到這有如人間的另一個世外桃源，完全沒有任何的殺氣，反而
充滿了祥和。溫暖的氣氛，四周圍充滿了迷霧，你不禁深深的吸了一
口氣，吸入體內後忽然感覺整個人變得更有精神與活力，隨性的找個
地方坐下運行內力，發覺自己的內力修為增進了不少。


妳發覺藍色的迷霧圍繞正在妳四周

LONG);
	setup();
	replace_program(ROOM);
}
