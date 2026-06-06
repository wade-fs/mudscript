inherit ROOM;
void create() {
	set( "short", "$HIR$菜$HIG$園$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10309 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room69",
	]) );
	set( "long", @LONG
海格在學校的外圍建了一個菜園,主要種植南瓜和其他蔬菜,而南瓜
除了可以有南瓜汁可以喝之外,萬聖節時還可以當作燈飾,海格有時
也會在這裡教授奇獸飼育學,不過海格對於猛獸的看法顯然和一般人
不一樣,越危險他越愛,菜園旁還有被爆尾釘蝦噴火燒毀的痕跡

LONG);
	setup();
	replace_program(ROOM);
}
