inherit ROOM;
void create() {
	set( "short", "吉祥花園" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount5"  : 484,
		"amount10" : 40,
		"amount2"  : 138,
		"file7"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/ping/obj/poison_pill",
		"amount6"  : 654,
		"amount8"  : 749,
		"file1"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file3"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 658,
		"amount7"  : 679,
		"amount1"  : 677,
		"file5"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"amount3"  : 798,
		"amount4"  : 818,
	]) );
	set( "build", 10014 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room430",
		"east"      : "/open/clan/13_luck/room/room193.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這兒是黃城大道旁的吉祥花園，從這放眼過去一大片的花花草草，
平常時可以看到一些公主或是宮女在這賞花嬉戲，蝴蝶蜜蜂相互爭艷，
許多聞香而來的達官貴人，不免心花怒放，看著只穿一件薄紗隱隱約約
可以看見裡面只穿著小可愛的少女們，惹的遠觀的人心理養養的。

LONG);
	setup();
	replace_program(ROOM);
}
