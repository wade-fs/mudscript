inherit ROOM;
void create() {
	set( "short", "吉祥花園" );
	set( "object", ([
		"amount1"  : 50,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 50,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 50,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 50,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 50,
		"amount2"  : 50,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 50,
		"amount7"  : 50,
	]) );
	set( "owner", "zmud" );
	set( "build", 10869 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room431",
		"west"      : "/open/clan/13_luck/room/room432.c",
		"east"      : "/open/clan/13_luck/room/room4.c",
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
