inherit ROOM;
void create() {
	set( "short", "狂殘魔-浪子居" );
	set( "object", ([
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/soil-ball",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"amount7"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/obj/soil-ball",
		"amount10" : 1,
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount9"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file9"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "roar" );
	set( "build", 10302 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room184",
		"south"     : "/open/clan/13_luck/room/room88.c",
		"east"      : "/open/clan/13_luck/room/room185.c",
	]) );
	set( "long", @LONG
你踏進此地，看見六個字”狂殘魔-浪子居”只覺得心中泛起一股莫
名的恐懼，此時想到”浪子居 ”，才知道原來進了浪子的地盤，這是風
魔浪子的房間，但四周圍並無什麼東西，只是一眼望去，皆看不到盡頭，
等你走到最近的一面牆時，發現牆上都是刀痕，由此可知浪子的功力及為
三斬、刀皇跟妖刀所做下的努力。


LONG);
	setup();
	replace_program(ROOM);
}
