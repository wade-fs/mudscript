inherit ROOM;
void create() {
	set( "short", "藏寶室" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_boots",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_pants",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
	]) );
	set( "build", 10545 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/hall.c",
		"west"      : "/open/clan/13_luck/room/room138.c",
		"north"     : "/open/clan/13_luck/room/room140.c",
		"south"     : "/open/clan/13_luck/room/room141",
		"enter"     : "/open/clan/13_luck/room/room179",
		"east"      : "/open/clan/13_luck/room/room137.c",
	]) );
	set( "long", @LONG

　　言語說不上來的森嚴，心跳如雷鳴般清楚的沉靜，這裡是十三吉
祥的機防最重地，十三吉祥藏寶室，這是一個由黑金石洞打成的山洞
入口，入門就看到四個大字『 十三吉祥』。往北過去是葵花聚氣室，
放有FORCE   EQ，讓你衝破內功瓶頸。南方為藏經閣，收藏天下武林
秘笈。西邊為龍鱗廳，收藏著自黃金甲龍身上取下的鱗片「魔龍麟」
。往東過去為丹藥房，裡頭存放著十三長老們，在火龍幻界打敗六色
龍，得來不易的丹藥。

LONG);
	setup();
	replace_program(ROOM);
}
