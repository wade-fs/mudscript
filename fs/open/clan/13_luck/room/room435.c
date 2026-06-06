inherit ROOM;
void create() {
	set( "short", "吉祥花園" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/prayer/obj/lin-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"file8"    : "/open/prayer/obj/lin-head",
		"amount3"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
		"file10"   : "/open/prayer/obj/lin-head",
	]) );
	set( "build", 10133 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room433",
		"west"      : "/open/clan/13_luck/room/room197",
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
