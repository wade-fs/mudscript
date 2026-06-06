inherit ROOM;
void create() {
	set( "short", "黃色龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 11017 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room582",
	]) );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是黃龍的精華，吃了黃色龍元，可
以讓書生跟劍客更能隨心所欲的控制他的武器，更有力氣奮勇殺敵。

LONG);
	setup();
	replace_program(ROOM);
}
