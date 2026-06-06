inherit ROOM;
void create() {
	set( "short", "綠色龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/golden-ball",
		"amount7"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"amount5"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/golden-ball",
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"file3"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/wood-ball",
	]) );
	set( "build", 27673 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room591.c",
		"north"     : "/open/clan/13_luck/room/room755",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是綠龍的精華，吃了綠色龍元，可
以讓刀客感應的刀中的刀魂頓時之間刀氣可以暴漲一倍多，殺起敵人來
更加輕鬆寫意。

LONG);
	setup();
	replace_program(ROOM);
}
