inherit ROOM;
void create() {
	set( "short", "小豬頭的盥洗室" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"amount5"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file10"   : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/obj/soil-ball",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file9"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "owner", "pighead" );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room412",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的盥洗室，當每天小豬頭回到家中，第一件事
就是洗個熱水澡，讓自己的身心放鬆，這樣才有活力去應付明天的挑
戰，這邊有個很大的浴缸，小豬頭喜歡跟許多女生一起泡澡，那種感
覺真是最高的享受。

LONG);
	setup();
	replace_program(ROOM);
}
