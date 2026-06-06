inherit ROOM;
void create() {
	set( "short", "小南家前廳" );
	set( "owner", "amdxp" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 100,
		"file8"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 111,
		"amount6"  : 161,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount5"  : 179,
		"file4"    : "/open/mon/obj/thousand-nectar",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 245,
		"amount4"  : 70,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 195,
		"amount9"  : 100,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 170,
		"amount7"  : 200,
	]) );
	set( "build", 10020 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room70",
		"west"      : "/open/clan/13_luck/room/room69.c",
		"east"      : "/open/clan/13_luck/room/room68.c",
		"out"       : "/open/clan/13_luck/room/room66.c",
	]) );
	set( "long", @LONG

　　歡迎您來到小南的第四度空間次元，一起分享小南的豐功偉業，此
空間中充滿了銀水藍色的微小粒子，是由天地人三度空間中匯集到金木
水火土五行中的真氣，吸入小南丹田內融合了六種浩然正氣所產生的粒
子，而產生的異次元。


妳發覺藍色的迷霧圍繞正在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
