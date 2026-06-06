inherit ROOM;
void create() {
	set( "short", "吉祥花園" );
	set( "owner", "killer" );
	set( "object", ([
		"file8"    : "/obj/gift/unknowdan",
		"amount5"  : 2000,
		"amount1"  : 150,
		"amount6"  : 1,
		"amount10" : 1,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 202,
		"amount3"  : 220,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file5"    : "/open/killer/obj/s_pill",
		"amount2"  : 366,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"amount7"  : 1,
	]) );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room434",
		"west"      : "/open/clan/13_luck/room/room4.c",
		"east"      : "/open/clan/13_luck/room/room435.c",
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
