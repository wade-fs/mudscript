inherit ROOM;
void create() {
	set( "short", "風雲道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file3"    : "/open/gsword/obj1/blosword",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 28,
		"amount7"  : 1,
		"amount2"  : 21,
		"file5"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/killer/obj/s_pill",
		"file4"    : "/open/killer/obj/dagger",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/blood-water",
		"amount10" : 1,
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/obj/wood-ball",
		"amount8"  : 1,
		"amount1"  : 140,
		"file8"    : "/open/gsword/obj1/blosword",
		"file9"    : "/obj/gift/bingtang",
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"amount3"  : 1,
	]) );
	set( "build", 10650 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room340",
		"south"     : "/open/clan/13_luck/room/room338",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你急躍而起轉身四望，冷月當空，銀光遍地，空山寂寂，花影重
重四下里山谷嗚響，你繼續急奔前去。再過拳柱香時分，你跨開大步
，覺得風生耳際，兩樹木花草不住的倒退，郤地有如快馬奔馳。你大
袖飄飄努力前去。此時微風徐徐吹來，天上的雲層也有點兒飄忽不定
，令你覺的毛骨聳然。

LONG);
	setup();
	replace_program(ROOM);
}
