inherit ROOM;
void create() {
	set( "short", "毒龍龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10303 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room582",
	]) );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是毒龍的精華，吃了毒色龍元，不
但不會中毒，反而可以讓人清楚的感受到天地的靈氣，對於修習靈力和
法力的修道人，是非常好用的補品。

LONG);
	setup();
	replace_program(ROOM);
}
