inherit ROOM;
void create() {
	set( "short", "武神居" );
	set( "object", ([
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount5"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/badman/obj/mask",
		"amount4"  : 606,
		"file4"    : "/open/ping/obj/poison_pill",
		"amount3"  : 663,
	]) );
	set( "build", 10184 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room679.c",
		"south"     : "/open/clan/13_luck/room/room681.c",
		"west"      : "/open/clan/13_luck/room/room678",
	]) );
	set( "long", @LONG

    經過彩虹七陣迷陣的試煉，終於來到赫赫有名武神的
不凡居所。巨大的扁額高掛，從外面就可以感覺到裡面強
大的魄氣寫著大大的三個字─『武神居』，樸實的擺設，
顯示出武神的『沉穩內斂』。雖被譽為武中之神，卻為人
謙虛，絲毫不高傲。

LONG);
	setup();
	replace_program(ROOM);
}
