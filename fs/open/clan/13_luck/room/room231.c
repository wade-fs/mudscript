inherit ROOM;
void create() {
	set( "short", "＠小賢藏寶庫＠" );
	set( "object", ([
		"file5"    : "/open/mon/obj/mon-pill",
		"amount4"  : 191,
		"amount1"  : 272,
		"file3"    : "/obj/stone/suipian",
		"amount2"  : 2,
		"amount6"  : 1,
		"file2"    : "/obj/stone/jiao",
		"file6"    : "/open/capital/obj/king-boots",
		"file4"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/obj/stone/powder",
		"amount5"  : 279,
		"amount3"  : 28,
	]) );
	set( "owner", "romi" );
	set( "build", 10293 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room287",
		"west"      : "/open/clan/13_luck/room/room101.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你一進門就被無數耀眼的光芒所吸引，仔細一看竟是全狂想最強
的武器和防具頓時感到不可思議，竟有人有如此能耐能取得如此強力
的東西心中暗道真強，穿上後感覺全身的戰鬥力跟防禦力都提昇了不
少，整裝後馬上出發戰鬥～～～～殺

LONG);
	setup();
	replace_program(ROOM);
}
