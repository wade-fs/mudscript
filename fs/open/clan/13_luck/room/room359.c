inherit ROOM;
void create() {
	set( "short", "煉丹偏房" );
	set( "object", ([
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 418,
		"amount6"  : 25,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file1"    : "/open/doctor/pill/sky_pill",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount5"  : 42,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"file5"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 11526 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room362",
		"west"      : "/open/clan/13_luck/room/room144.c",
		"south"     : "/open/clan/13_luck/room/room361.c",
		"north"     : "/open/clan/13_luck/room/room360.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    而這裡是存放著銀真們所製作出來的部分丹藥，有天靈丹－其功
能為解除狀態，有地靈丹－其功能為解毒，在這裡還可以找到另一種
也是可以解毒的天然丹藥名為百花清心露，在人間只有四個人擁有此
藥。

LONG);
	setup();
	replace_program(ROOM);
}
