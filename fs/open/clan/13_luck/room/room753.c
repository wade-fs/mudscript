inherit ROOM;
void create() {
	set( "short", "藍色龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10647 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room582",
	]) );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是藍龍的精華，功用是可以暫時提
升一甲子的內功，比練了什麼絕世的內功來的快又有效。

LONG);
	setup();
	replace_program(ROOM);
}
