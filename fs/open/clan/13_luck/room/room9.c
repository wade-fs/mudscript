inherit ROOM;
void create() {
	set( "short", "十三錢莊" );
	set( "build", 10900 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/hall.c",
		"up"        : "/open/clan/13_luck/room/room40.c",
	]) );
	set( "long", @LONG

    古人云：錢不是萬能的，但是沒錢卻是萬萬不能。現今的十三吉
祥屬於草創的時候，需要很多的人力跟物力，希望身為十三的一員能
夠有錢的出錢，有力的出力。讓十三吉祥再一次的活耀於狂想空間，
最終目標：　　
　　　　　　　　～～～成為武林中最大幫派～～～

LONG);
	setup();
	replace_program(ROOM);
}
