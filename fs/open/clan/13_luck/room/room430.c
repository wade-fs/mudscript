inherit ROOM;
void create() {
	set( "short", "吉祥花園" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room432",
		"east"      : "/open/clan/13_luck/room/room431.c",
	]) );
	set( "long", @LONG

    這兒是黃城大道旁的吉祥花園，從這放眼過去一大片的花花草草，
平常時可以看到一些公主或是宮女在這賞花嬉戲，蝴蝶蜜蜂相互爭艷，
許多聞香而來的達官貴人，不免心花怒放，看著只穿一件薄紗隱隱約約
可以看見裡面只穿著小可愛的少女們，惹的遠觀的人心理養養的。

LONG);
	setup();
	replace_program(ROOM);
}
