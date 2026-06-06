inherit ROOM;
void create() {
	set( "short", "風起雲湧樓" );
	set( "build", 11388 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room244.c",
		"south"     : "/open/clan/13_luck/room/room246.c",
	]) );
	set( "long", @LONG

    江山輩有人才出，一代新人換舊人，十三吉祥有著傳說中的幫主
小南的人才培育中心，教導出不少的好人才，一位位都是以後的準大
將，也在小南的指導下，可以自行去解迷的 save eq才能算是合格，
也讓十三吉祥殿定壯大的基礎。

LONG);
	setup();
	replace_program(ROOM);
}
