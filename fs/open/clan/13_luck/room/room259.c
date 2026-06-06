inherit ROOM;
void create() {
	set( "short", "『石板路』 " );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"file1"    : "/open/mogi/dragon/obj/dragon-head",
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
	]) );
	set( "build", 10701 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room260.c",
		"south"     : "/open/clan/13_luck/room/room258",
	]) );
	set( "long", @LONG
走出了桃花林之後，才發覺剛剛的桃花林只是嚇唬人的，並不是故意要製造
迷宮來阻擋陌生人的進出，那只是住在「桃雲小築」裡的主人要嚇唬嚇唬入侵者
而已。聽說住在這片桃花林的是兩個隱士，平常不太在意江湖上的事情，而剛剛
那片桃花林就是居住在這裡的隱士所佈下的陣局，目的也只是喝止隨隨便便的入
侵者而已，而並沒有要傷害人的心。
LONG);
	setup();
	replace_program(ROOM);
}
