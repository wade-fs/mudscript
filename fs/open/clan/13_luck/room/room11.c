inherit ROOM;
void create() {
	set( "short", "綺玉門" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file1"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file3"    : "/open/mogi/castle/obj/blood-water",
		"amount8"  : 4,
		"amount9"  : 2,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount6"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount7"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount3"  : 11,
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10093 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room228.c",
		"south"     : "/open/clan/13_luck/room/room8.c",
		"enter"     : "/open/clan/13_luck/room/room697",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

　　你已進入了皇城的中心，一道宏偉的巨門聳立在你眼前，門崁上刻
著--- 綺玉門三個大字，此乃通往皇城主殿青龍殿的唯一道路，青龍殿
乃皇城內最神秘之地，凡十三吉祥內等級較高之高手，皆在內修行，從
這裡就能感覺到有一股強大的氣流從裡面傳來，所有的大內高手，隨時
聽從幫主的傳喚。

LONG);
	setup();
	replace_program(ROOM);
}
