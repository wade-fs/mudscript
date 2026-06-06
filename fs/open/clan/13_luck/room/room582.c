inherit ROOM;
void create() {
	set( "short", "紅色龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"amount10" : 1,
	]) );
	set( "build", 10124 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room752.c",
		"west"      : "/open/clan/13_luck/room/room754",
		"out"       : "/open/clan/13_luck/room/room745.c",
		"north"     : "/open/clan/13_luck/room/room591.c",
		"east"      : "/open/clan/13_luck/room/room753.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是紅龍的精華，吃了紅色龍元，看
敵人的動作就好像慢動作一樣，看的一清二楚，所以可以很輕易的閃過
任何凌厲的攻勢。

LONG);
	setup();
	replace_program(ROOM);
}
