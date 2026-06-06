inherit ROOM;
void create() {
	set( "short", "小豬頭的二樓" );
	set( "object", ([
		"amount5"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/fire-ball",
		"file5"    : "/obj/stone/suipian",
		"amount10" : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file9"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "pighead" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room411.c",
		"north"     : "/open/clan/13_luck/room/room409.c",
		"south"     : "/open/clan/13_luck/room/room408",
		"west"      : "/open/clan/13_luck/room/room410.c",
		"down"      : "/open/clan/13_luck/room/room127",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的二樓大廳，以這邊為中心，分別有東西南北
方向，往東邊是主臥房，是小豬頭平常休息的地方，往西邊是客房，
提供外來客人住宿的地方，往北邊為盥洗室，是小豬頭累了一天後可
以好好放鬆身心的場所，往南邊是娛樂場所，讓小豬頭可以看他最喜
歡的動作片(簡稱A片)。

LONG);
	setup();
	replace_program(ROOM);
}
